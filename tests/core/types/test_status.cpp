#include <types/status.hpp>

#include <gtest/gtest.h>

TEST(TypesStatus, ConstructionByValueSetsMemberFieldsCorrectly) {
  {
    Types::Status status{Types::Status::Code::Okay};
    EXPECT_TRUE(status.isOkay());
    EXPECT_EQ(Types::Status::Code::Okay, status.getCode());
    EXPECT_TRUE(status.getMessage().empty());
  }

  {
    Types::Status status{Types::Status::Code::PreconditionFailed};
    EXPECT_FALSE(status.isOkay());
    EXPECT_EQ(Types::Status::Code::PreconditionFailed, status.getCode());
    EXPECT_TRUE(status.getMessage().empty());
  }

  {
    Types::Status status{Types::Status::Code::PreconditionFailed,
                         "test message"};
    EXPECT_FALSE(status.isOkay());
    EXPECT_EQ(Types::Status::Code::PreconditionFailed, status.getCode());
    EXPECT_EQ("test message", status.getMessage());
  }
}

TEST(TypesStatus, FactoryOkayReturnsSuccessStatus) {
  Types::Status status{Types::Status::Okay()};
  EXPECT_TRUE(status.isOkay());
  EXPECT_TRUE(status.getMessage().empty());
}

TEST(TypesStatus, ToStringReturnsExpectedString) {
  {
    Types::Status status{Types::Status::Okay()};
    EXPECT_EQ("Okay", status.toString());
  }

  {
    Types::Status status{Types::Status::Code::PreconditionFailed};
    EXPECT_EQ("Precondition Failed", status.toString());
  }

  {
    Types::Status status{Types::Status::Code::PreconditionFailed,
                         "test message"};
    EXPECT_EQ("Precondition Failed: test message", status.toString());
  }
}
