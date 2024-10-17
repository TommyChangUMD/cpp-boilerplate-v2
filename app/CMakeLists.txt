# Find OpenCV library.
# To install opencv on Ubuntu, do:
#    sudo apt install libopencv-dev
find_package(OpenCV REQUIRED)

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
  ${OpenCV_INCLUDE_DIRS}
  )

# Any libries that needed to linked with this target.
# Note: we do not need to specify additional libraries for the
# dependent libraries, they are automatically included.
target_link_libraries(shell-app
  ${OpenCV_LIBS}
  )

