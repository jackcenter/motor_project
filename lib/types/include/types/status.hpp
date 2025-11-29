#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <string_view>
#include <iostream>

namespace Types {
/**
 * @brief Simple status class to represent success or error states.
 */
class Status {
public:
    enum class Code {
        Okay = 0,
        PreconditionFailed,
    };

    Status(Code code, std::string message = "") : code_(code), message_(std::move(message)) {}

    static Status Okay() { return Status(Code::Okay); }

    Code getCode() const { return code_; }

    const std::string_view getMessage() const { return message_; }

    bool isOkay() const { return code_ == Code::Okay; }
    
private:
    Code code_;
    std::string message_;
};
} // namespace types

#endif  // TYPES_H
