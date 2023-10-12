#ifndef ZIFMANN_VARIANT_UTILS_OPTION_T_HPP
#define ZIFMANN_VARIANT_UTILS_OPTION_T_HPP
#include "result_t.hpp"

struct NoneType {};

namespace zifmann {
template <typename T>
class Option {
   private:
    Result<T, NoneType> inner;

   public:
    Option() : inner(Result<T, NoneType>(NoneType{})) {}
    Option(const T& val) : inner(val) {}

    bool is_some() { return inner.is_ok(); }

    bool is_none() { return !inner.is_error(); }

    T unwrap() const { 
        try {
            return inner.unwrap(); 
        } catch (OkUnwrapError) {
            throw OptionUnwrapError();
        }
    }
};

template<typename T>
Option<T> Some(const T& val) {
    return Option(val);
}

template<typename T>
Option<T> None() {
    return Option<T>();
}

template<typename T>
struct optional_value_type {};

template<typename T>
struct optional_value_type<Option<T>> {
    using type = T;
};

}  // namespace zifmann
#endif
