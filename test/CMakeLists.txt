# Any C++ source files needed to build this target (fooBarTest).
add_executable(fooBarTest
  # list of source cpp files:
  main.cpp
  fooBarTest.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(fooBarTest PUBLIC
  # list of include directories:
  )

# Any dependent libraires needed to build this target.
target_link_libraries(fooBarTest PUBLIC
  # list of libraries:
  gtest
  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(fooBarTest)
