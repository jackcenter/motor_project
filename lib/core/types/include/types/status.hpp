/**
 * @file status.hpp
 * @brief Declaration of the Status type used for error reporting.
 *
 * @author Jack Center
 * @date November 29th, 2025
 */

#ifndef TYPES_STATUS_HPP
#define TYPES_STATUS_HPP

#include <iostream>
#include <fmt/format.h>
#include <string>
#include <string_view>

namespace Types {
/**
 * @class Status
 * @brief Represents success or error states.
 */
class Status {
public:
  /**
   * @enum
   * @brief Error code classifications.
   *
   * Error codes should be selected based on the following descriptions:
   * - Okay - function executed normally.
   * - PreconditionFailed - a requirement for function execution was not met.
   */
  enum class Code {
    Okay = 0,
    PreconditionFailed,
  };

  /**
   * @brief Constructs the status directly from the `code` and `message`.
   */
  Status(Code code, const std::string& message = "");

  /**
   * @brief Factory constructor that returns an `Okay` `Status`.
   */
  static Status Okay();

  /**
   * @brief Returns the `code_`.
   */
  Code getCode() const;

  /**
   * @brief Returns the `message_`.
   */
  std::string_view getMessage() const;

  /**
   * @brief Returns true if the `code_` is `Okay`, false otherwise.
   */
  bool isOkay() const;

  /**
   * @brief Returns the `code_` and `message_` as a combined string.
   */
  std::string toString() const;

private:
  Code code_;
  std::string message_;
};

/**
 * @brief Writes the Status code and message to the output stream.
 */
std::ostream &operator<<(std::ostream &os, const Status &status);

// ---------------------------------------- Implementation ----------------------------------------
Status::Status(Code code, const std::string& message)
    : code_(code), message_(std::move(message)) {}

Status Status::Okay() { return Status(Code::Okay); }

Status::Code Status::getCode() const { return code_; }

std::string_view Status::getMessage() const { return message_; }

bool Status::isOkay() const { return code_ == Code::Okay; }

std::string Status::toString() const {
  switch (code_) {
  case Code::Okay:
    return "Okay";
  case Code::PreconditionFailed:
    if (getMessage().empty()) {
      return "Precondition Failed";
    }
    return fmt::format("Precondition Failed: {}", message_);
  default:
    if (getMessage().empty()) {
      return "Unknown";
    }
    return fmt::format("Unknown: {}", message_);
  }
}

std::ostream &operator<<(std::ostream &os, const Status &status) {
  os << status.toString();
  return os;
}
} // namespace Types

#endif // TYPES_STATUS_HPP
