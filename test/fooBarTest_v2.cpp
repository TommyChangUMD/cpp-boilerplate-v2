#include <gtest/gtest.h>
#include <string>

#include "fooBar.hpp"

//
// Google Test exercise:
// ref: https://www.linkedin.com/learning/test-driven-development-in-c-plus-plus
//
// Write a funtion that receives and prints a passed in number.
// - When the input is multiple of 3, print "Foo"
// - When the input is multiple of 5, print "Bar"
// - When the input both multiple of 3 and 5, print "FooBar"
//

// Tests:
//  - [X] Can call the fooBar() function
//  - [X] Get "1" when presss 1.
//  - [X] Get "2" when presss 2.
//  - [X] Get "Foo" when presss 3.
//  - [X] Get "Bar" when presss 5.
//  - [X] Get "Foo" when presss 6.
//  - [X] Get "Bar" when presss 10.
//  - [X] Get "FooBar" when presss 15.
//  - [X] Get "FooBar" when presss 30.


TEST(FooBarTest_v2, canCallFooBar) {
  FooBar fooBar;
  std::string result = fooBar.Process (1);
}

TEST(FooBarTest_v2, returns1With1PassIn) {
  FooBar fooBar;
  std::string result = fooBar.Process (1);
  ASSERT_STREQ("1", result.c_str());
}

class FooBarTests : public testing::Test {
public:

protected:
  void SetUp() override {
    std::cout << "Calling Fixture SetUp\n";
  };
  
  void TearDown () override {
    std::cout << "Calling Fixture TearDown\n";
  };

  FooBar fooBar;
};

TEST_F(FooBarTests, returns2With2PassIn) {
  std::string result = fooBar.Process (2);
  ASSERT_STREQ("2", result.c_str());
}

// TEST(FooBarTest_v2, returnsFooWith3PassIn) {
//   std::string result = fooBar (3);
//   ASSERT_STREQ("Foo", result.c_str());
// }

// TEST(FooBarTest_v2, returnsBarWith5PassIn) {
//   std::string result = fooBar (5);
//   ASSERT_STREQ("Bar", result.c_str());
// }

// TEST(FooBarTest_v2, returnsFooWith6PassIn) {
//   std::string result = fooBar (6);
//   ASSERT_STREQ("Foo", result.c_str());
// }

// TEST(FooBarTest_v2, returnsBarWith10PassIn) {
//   std::string result = fooBar (10);
//   ASSERT_STREQ("Bar", result.c_str());
// }

// TEST(FooBarTest_v2, returnsFooBarWith15PassIn) {
//   std::string result = fooBar (15);
//   ASSERT_STREQ("FooBar", result.c_str());
// }

// TEST(FooBarTest_v2, returnsFooBarWith30PassIn) {
//   std::string result = fooBar (30);
//   ASSERT_STREQ("FooBar", result.c_str());
// }


