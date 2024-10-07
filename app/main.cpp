#include "lib.hpp"
#include "lib1.hpp"
#include "lib2.hpp"

int main() {
  dummy();
  my_function1(30);
  bool cond = true;
  if (cond)
    my_function2(30.3);
  return 0;
}
