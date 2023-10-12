#include "result_t.hpp"
#include <type_traits>

#define OK(var, res) \
    (bool _if_let_ok = res.is_ok(); _if_let_ok) \
        for (first_type<decltype(res)>::type var = res.unwrap(); _if_let_ok; _if_let_ok = false)

#define ERR(var, res) \
    (bool _if_let_ok = res.is_ok(); _if_let_ok) \
        for (second_type<decltype(res)>::type var = res.error(); _if_let_ok; _if_let_ok = false)
