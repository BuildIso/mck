#ifndef MCK_CPP_CORE_RESULT_HPP
#define MCK_CPP_CORE_RESULT_HPP

namespace mck {

enum class result_state {
    ok,
    error
};

template<typename T>
class result {
public:
    static result ok(const T& value) {
        return result(value, result_state::ok);
    }

    static result error(const T& value) {
        return result(value, result_state::error);
    }

    bool is_ok() const {
        return state_ == result_state::ok;
    }

    bool is_error() const {
        return state_ == result_state::error;
    }

    const T& value() const {
        return value_;
    }

private:
    result(const T& v, result_state s)
        : value_(v), state_(s) {}

    T value_;
    result_state state_;
};

class status {
public:
    static status ok() {
        return status(result_state::ok);
    }

    static status error() {
        return status(result_state::error);
    }

    bool is_ok() const {
        return state_ == result_state::ok;
    }

    bool is_error() const {
        return state_ == result_state::error;
    }

private:
    explicit status(result_state s)
        : state_(s) {}

    result_state state_;
};

template<typename T>
class result_ref {
public:
    static result_ref ok(T* ptr) {
        return result_ref(ptr, result_state::ok);
    }

    static result_ref error(T* ptr) {
        return result_ref(ptr, result_state::error);
    }

    bool is_ok() const {
        return state_ == result_state::ok;
    }

    bool is_error() const {
        return state_ == result_state::error;
    }

    T* get() const {
        return ptr_;
    }

private:
    result_ref(T* p, result_state s)
        : ptr_(p), state_(s) {}

    T* ptr_;
    result_state state_;
};

}

#endif
