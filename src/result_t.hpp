#include <variant>

#include "errors.hpp"

namespace zifmann {

template <typename T, typename E>
class Result {
   private:
    std::variant<T, E> value;
    bool ok;

   public:
    Result(const T& ok): value(ok), ok(true) {}
    Result(const E& err): value(err), ok(false) {}
    bool is_ok() const { return ok; }

    bool is_error() const { return !ok; }

    T unwrap() const {
        if (ok) {
            return std::get<T>(value);
        } else {
            throw UnwrapError();
        }
    }

    E error() const {
        if (!ok) {
            return std::get<E>(value);
        } else {
            throw ErrorUnwrapError();
        }
    }

    bool Ok(const T *alias) const {
        if (ok) {
            alias = &std::get<T>(value);
            return true;
        }
        return false;
    }

    bool Err(E *alias) const {
        if (!ok) {
            alias = &value;
            return true;
        }
        return false;
    }
};

template <typename T, typename E>
Result<T, E> Ok(const T &ok) {
    return Result<T, E>(ok);
}

template <typename T, typename E>
Result<T, E> Err(const E &error) {
    return Result<T, E>(error);
}

template<typename T>
struct first_type;

template<typename T>
struct second_type;

template<typename T, typename E>
struct first_type<Result<T, E>> {
    using type = T;
};

template<typename T, typename E>
struct second_type<Result<T, E>> {
    using type = E;
};

}  // namespace zifmann
