#ifndef MCK_VECTOR_HPP
#define MCK_VECTOR_HPP

extern "C" {
#include "core.h"
}

namespace mck {

template<typename T, mck_u32 Capacity>
class Vector {
public:
    Vector() : count(0) {}

    bool push(const T& value) {
        if (count >= Capacity) return false;
        data[count++] = value;
        return true;
    }

    T& operator[](mck_u32 index) {
        return data[index];
    }

    const T& operator[](mck_u32 index) const {
        return data[index];
    }

    mck_u32 size() const {
        return count;
    }

private:
    T data[Capacity];
    mck_u32 count;
};

}

#endif
