# Any C++ source files needed to build this target (shell-app).
add_executable(shell-app
  # list of source cpp files:
  AnalogSensor.cpp
  main.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(shell-app PUBLIC
  # list inclue directories:
  ${CMAKE_SOURCE_DIR}/include
)

# Use static linking to create a stand-alone executable.
target_link_options(shell-app PUBLIC --static)
