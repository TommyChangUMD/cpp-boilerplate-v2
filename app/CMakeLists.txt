# Any C++ source files needed to build this target (shell-app).
add_executable(shell-app
  # list of source cpp files:
  GMockTest.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(shell-app PUBLIC
  # list inclue directories:
)

