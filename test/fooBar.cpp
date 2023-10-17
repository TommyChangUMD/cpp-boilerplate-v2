
#include "fooBar.hpp"

//
// Constructor
//

FooBar::FooBar() {
};


//
// Destructor
//

FooBar::~FooBar() {
};


//
// proceess
//

std::string FooBar::Process(int val) {
  if (IsMultiple (val, 3) && IsMultiple (val, 5)) 
    return "FooBar";
  
  if (IsMultiple (val, 3))
    return ("Foo");

  if (IsMultiple (val, 5))
    return ("Bar");

  return std::to_string(val);
}


//
// IsMultiple
//

bool FooBar::IsMultiple (int val, int factor) {
  return ((val % factor) == 0);
}


