#ifndef MCK_CORE_HPP
#define MCK_CORE_HPP

extern "C" {
#include "core.h"
}

namespace mck {

class Core {
public:
    static void init() {
        core_init();
    }

    static bool ready() {
        return core_is_ready() != 0;
    }

    static void setLogger(mck_log_fn fn) {
        core_set_logger(fn);
    }

    static void log(const char* msg) {
        core_log(msg);
    }
};

}

#endif
