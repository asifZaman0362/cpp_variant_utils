#include <exception>

namespace zifmann {
class UnwrapError : public std::exception {
   public:
    const char *what() const noexcept override {
        return "Attempt to unwrap() an error value";
    }
};

class ErrorUnwrapError : public std::exception {
   public:
    const char *what() const throw() override {
        return "Attempt to error() an ok value";
    }
};
}  // namespace zifmann
