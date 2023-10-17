#pragma once

#include <string>

class FooBar {
public:
  FooBar ();
  ~FooBar ();

  std::string Process(int val);

private:
  bool IsMultiple (int val, int factor);
};

