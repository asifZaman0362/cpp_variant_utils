#include <iostream>
#include <string>
#include <cmath>

#include "src/result.hpp"
#include "src/option.hpp"

enum class Token {
    Comma, Bracket, Literal
};

enum class ParseError {
    InvalidCharacter,
    ReachedEof
};

int user_input;
std::string string = "";

using namespace zifmann;

using ArithmeticError = std::string;

Result<Token, ParseError> Parse(const std::string& str) {
    // parse
    return Err<Token>(ParseError::InvalidCharacter);
}

Result<float, ArithmeticError> square_root(float x) {
    if (x < 0) {
        return Err<float>(std::string("only real roots are allowed!"));
    } else {
        return Ok<float, ArithmeticError>(sqrt(x));
    }
}

struct Server {
    Option<std::string> username;
};

int main() {
    int sqrt10 = square_root(10).unwrap(); // sqrt(10) will never fail,
                                           // so we can unwrap safely to directly get the value, 
                                           // skipping any checks
    // sqrt might fail when some arbitrary user input,
    if OK(val, square_root(user_input)) {  // similar to if let Ok(val) binding in Rust
        std::cout << "square root = " << val << "\n";
    } else {
        // std::cout << val; // val is only bound inside the if (true) branch block
        std::cout << "must be a positive number!\n";
    }
    auto parse_res = Parse(string);
    if OK(token, parse_res) {               // if let binding, again
        switch (token) {
            case Token::Comma:
                // ... do stuff
                break;
            default:
                break;
        }
    } else {                                // in case parse_res resulted in an error
        auto error = parse_res.error();     // in the else branch, unwrap the error safely
        switch (error) {
            case ParseError::ReachedEof:
                std::cout << "Reached end of file!\n";
                break;
            case ParseError::InvalidCharacter:
                std::cout << "Unexpected character found in the stream!\n";
                break;
        }
    }

    Server server;
    server.username = None<std::string>();
    try { // the try catch is obviously only for demonstration purposes,
          // with our Result type, we don't need to use try {} catch anymore
        server.username.unwrap();
    } catch (OptionUnwrapError) {
        server.username = Some(std::string("asif zaman"));
        if SOME(username, server.username) {
            std::cout << "Hello, " << username << "!\n";
        } else {
            std::cout << "hello darkness!\n";
        }
        server.username = None<std::string>();
        if SOME(username, server.username) {
            std::cout << "Hello, " << username << "!\n";
        } else {
            std::cout << "hello darkness!\n";
        }
    }
}

