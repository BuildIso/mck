#ifndef MCK_STRING_HPP
#define MCK_STRING_HPP

extern "C" {
#include "utils/string.h"
}

namespace mck {

class StringView {
public:
    StringView(const char* s) : str(s) {}

    mck_u32 length() const {
        return mck_str_len(str);
    }

    const char* c_str() const {
        return str;
    }

    int compare(const StringView& other) const {
        return mck_str_cmp(str, other.str);
    }

private:
    const char* str;
};

}

#endif
