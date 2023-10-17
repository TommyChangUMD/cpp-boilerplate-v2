#include <gtest/gtest.h>
#include <string>

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

bool IsMultiple (int val, int factor) {
  return ((val % factor) == 0);
}

std::string fooBar (int val) {
  if (IsMultiple (val, 3) && IsMultiple (val, 5)) 
    return "FooBar";
  
  if (IsMultiple (val, 3))
    return ("Foo");

  if (IsMultiple (val, 5))
    return ("Bar");

  return std::to_string(val);
}


TEST(FooBarTest, doesPass) {
  ASSERT_TRUE(true);
}

TEST(FooBarTest, canCallFooBar) {
  std::string result = fooBar (1);
}

TEST(FooBarTest, returns1With1PassIn) {
  std::string result = fooBar (1);
  ASSERT_STREQ("1", result.c_str());
}

TEST(FooBarTest, returns2With2PassIn) {
  std::string result = fooBar (2);
  ASSERT_STREQ("2", result.c_str());
}

TEST(FooBarTest, returnsFooWith3PassIn) {
  std::string result = fooBar (3);
  ASSERT_STREQ("Foo", result.c_str());
}

TEST(FooBarTest, returnsBarWith5PassIn) {
  std::string result = fooBar (5);
  ASSERT_STREQ("Bar", result.c_str());
}

TEST(FooBarTest, returnsFooWith6PassIn) {
  std::string result = fooBar (6);
  ASSERT_STREQ("Foo", result.c_str());
}

TEST(FooBarTest, returnsBarWith10PassIn) {
  std::string result = fooBar (10);
  ASSERT_STREQ("Bar", result.c_str());
}

TEST(FooBarTest, returnsFooBarWith15PassIn) {
  std::string result = fooBar (15);
  ASSERT_STREQ("FooBar", result.c_str());
}

TEST(FooBarTest, returnsFooBarWith30PassIn) {
  std::string result = fooBar (30);
  ASSERT_STREQ("FooBar", result.c_str());
}


