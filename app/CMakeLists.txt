# Find Eigen3 library.
# To install opencv on Ubuntu, do:
#    sudo apt install libeigen3-dev
find_package(Eigen3 REQUIRED)

# Any C++ source files needed to build this target (shell-app).
add_executable(shell-app
  # list of source cpp files:
  main.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(shell-app PUBLIC
  # list inclue directories:
  ${EIGEN3_INCLUDE_DIRS}
  )

# Any libries that needed to linked with this target.
# Note: we do not need to specify additional libraries for the
# dependent libraries, they are automatically included.
target_link_libraries(shell-app
  )

