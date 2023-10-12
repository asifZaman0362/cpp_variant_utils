#ifndef ZIFMANN_VARIANT_UTILS_OPTION_HPP
#define ZIFMANN_VARIANT_UTILS_OPTION_HPP
#include "option_t.hpp"
#include <type_traits>

#define SOME(var, opt) \
    (bool _if_let_some = opt.is_some(); _if_let_some) \
        for (optional_value_type<decltype(opt)>::type var = opt.unwrap(); _if_let_some; _if_let_some = false)
#endif
