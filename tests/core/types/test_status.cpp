#include <types/status.hpp>

#include <gtest/gtest.h>

TEST(Types, FactoryOkayWorks) {
  Types::Status status{ Types::Status::Okay() };
  EXPECT_TRUE(status.isOkay());    
}
