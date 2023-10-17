###########################################
# fooBarTest
###########################################

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


###########################################
# fooBarTest_v2 (use test fixture)
###########################################

# Any C++ source files needed to build this target (fooBarTest_v2).
add_executable(fooBarTest_v2
  # list of source cpp files:
  main.cpp
  fooBarTest_v2.cpp
  fooBar.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(fooBarTest_v2 PUBLIC
  # list of include directories:
  ./
  )

# Any dependent libraires needed to build this target.
target_link_libraries(fooBarTest_v2 PUBLIC
  # list of libraries:
  gtest
  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(fooBarTest_v2)


###########################################
# GMockTest
###########################################

# Any C++ source files needed to build this target (fooBarTest_v2).
add_executable(GMockTest
  # list of source cpp files:
  main.cpp
  GMockTest.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(GMockTest PUBLIC
  # list of include directories:
  ./
  )

# Any dependent libraires needed to build this target.
target_link_libraries(GMockTest PUBLIC
  # list of libraries:
  gtest
  gmock
  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(GMockTest)


###########################################
# GMockTest_v2 (use Test Fixture)
###########################################

# Any C++ source files needed to build this target (fooBarTest_v2).
add_executable(GMockTest_v2
  # list of source cpp files:
  main.cpp
  GMockTest_v2.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(GMockTest_v2 PUBLIC
  # list of include directories:
  ./
  )

# Any dependent libraires needed to build this target.
target_link_libraries(GMockTest_v2 PUBLIC
  # list of libraries:
  gtest
  gmock
  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(GMockTest_v2)
