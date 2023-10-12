#ifndef ZIFMANN_VARIANT_UTILS_ERRORS_HPP
#define ZIFMANN_VARIANT_UTILS_ERRORS_HPP
#include <exception>
#include <string>

namespace zifmann {
class UnwrapError : public std::exception {
   public:
    virtual const char *what() const noexcept = 0;
};

class OkUnwrapError : public UnwrapError {
   public:
    const char *what() const throw() override {
        return "Attempt to unwrap() an error value";
    }
};

class ErrorUnwrapError : public UnwrapError {
   public:
    const char *what() const throw() override {
        return "Attempt to error() an ok value";
    }
};

class OptionUnwrapError : public UnwrapError {
   public:
    const char *what() const throw() override {
        return "Attempt to unwrap() a None value";
    }
};

}  // namespace zifmann
#endif
