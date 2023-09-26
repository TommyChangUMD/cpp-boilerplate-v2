# cpp-boilerplate-v2

# C++ Boilerplate v2 Badges
![CICD Workflow status](https://github.com/TommyChangUMD/cpp-boilerplate-v2/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2/branch/main/graph/badge.svg)](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## Overview

Simple starter C++ project with:

- CMake
- GoogleTest

## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/TommyChangUMD/cpp-boilerplate-v2
  cd cpp-boilerplate-v2
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Run tests:
  cd build/; ctest; cd -
  # or if you have newer cmake
  ctest --test-dir build/
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

ref: https://cmake.org/cmake/help/latest/manual/cmake.1.html

## Building for code coverage (for assignments beginning in Week 4)

```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

This generates a index.html page in the build/test_coverage sub-directory that can be viewed locally in a web browser.
```

You can also get code coverage report for the *shell-app* target, instead of unit test. Repeat the previous 2 steps but with the *app_coverage* target:

``` bash
# Now, do another clean compile, run shell-app, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html

This generates a index.html page in the build/app_coverage sub-directory that can be viewed locally in a web browser.
```

## How to use GitHub CI to upload coverage report to Codecov

### First, sign up Codecov with you GitHub account.

  https://about.codecov.io/sign-up/

### Enable the repository you want to upload from

After you sign in, you should see a list of your repositories (you may
have to refresh and reload the page a few times). Enable the one you
want to receive coverage data from.

### Create a GitHub CI yaml file

See below for the setup of this repo:

https://github.com/TommyChangUMD/cpp-boilerplate-v2/blob/main/.github/workflows/run-unit-test-and-upload-codecov.yml

### Add your Codecov and GitHub CI badge to README.md

Follow the instruction below to copy the badge (in markdown format)
and paste it at the top of your README.md file.

For example:
#### CICD Workflow status

https://docs.github.com/en/actions/monitoring-and-troubleshooting-workflows/adding-a-workflow-status-badge

For example,

To generate the CICD badge for this particular repo, I put the line below in this README.md file:
``` markdown
![CICD Workflow status](https://github.com/TommyChangUMD/cpp-boilerplate-v2/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)
```
![CICD Workflow status](https://github.com/TommyChangUMD/cpp-boilerplate-v2/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)


#### Code Coverage Report
https://docs.codecov.com/docs/status-badges

For example, to generate the Code Coverage badge for this particular repo,  I put the line below in this README.md file:
``` markdown
[![codecov](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2/branch/main/graph/badge.svg)](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2)
```

[![codecov](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2/branch/main/graph/badge.svg)](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2)



Note: When you click on the codecov badge, you should see the coverage
report.  You should also see the source file listing.  If not, you may
need to login your codecov account first.


## Working with C++ IDE and LSP

You must set up clangd and use it with the C++ IDE of your choice. Most people use Visual Studio Code, but if you are using some other IDE, be sure to check if it supports the Language Server Protocol (LSP).

ref: https://clangd.llvm.org/installation.html


### clangd C++ language server setup

Run the [provided bash script][config-clangd.bash] or manually create the `~/.config/clangd/config.yaml` file with the following content:

[config-clangd.bash]: https://raw.githubusercontent.com/TommyChangUMD/cpp-boilerplate-v2/main/scripts/config-clangd.bash

```
Diagnostics:
  UnusedIncludes: Strict

CompileFlags:
  # Treat code as C++, use C++17 standard, enable more warnings.
  # Add: [-xc++, -std=c++17, -Wall, -Wno-missing-prototypes]
  Add: [-std=c++17]

  # Get rid of error [drv_unknown_argument]: Unknown argument: '-fprofile-abs-path'
  Remove: [-fprofile-abs-path]
```

This configuration instructs clangd to use C++-17 standard and catch any unused include files.  You are welcome to customize it further.   See https://clangd.llvm.org/config for more info.

### Visual studio code C++ IDE setup

Download vscode from https://code.visualstudio.com/docs/?dv=linux64_deb.

To install and it on your Ubuntu, do

``` bash
cd ~/Downloads
sudo dpkg -i code_1.81.1-1691620686_amd64.deb
code
```

Now, you must configure it to use clangd. Follow the instructions at https://clangd.llvm.org/installation.html#editor-plugins and look for "Visual Studio Code" under the `Editor plugins` section.

See https://github.com/clangd/vscode-clangd for more info.

### Emacs C++ IDE setup

If you use Emacs as your C++ IDE, then install eglot and supporting packages:
``` lisp
(package-initialize)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/"))
(package-refresh-contents)
(setq package-selected-packages '(eglot yasnippet company markdown-mode yasnippet-snippets cpp-auto-include))
(package-install-selected-packages)

```

Add to ~/.emacs:

``` lisp
(require 'eglot)
(add-to-list 'eglot-server-programs '((c++-mode c-mode) "clangd"))
```

See https://joaotavora.github.io/eglot/ for more info.



## Verify C++ IDE and LSP are working

clangd will automatically run (in the background) when invoked by the IDE. To verify that it's running correctly, you just need to check if the IDE can perform features such as code completion, finding declarations, references, definitions, and symbols, etc.

However, for clangd to work properly, it must ab able to find a file called `compile_commands.json` somewhere in your source code tree.  There are many ways to generate this compilation database file.  CMake can generate it for you already (this is done by using `CMAKE_EXPORT_COMPILE_COMMANDS` option).   Everytime you invoke the configuration command `cmake -S ./ -B build/`, cpp-boilerplate-v2 creates a symbolic link to the `compile_commands.json` file.

``` bash
  # generate compile_commands.json
  cmake -S ./ -B build/
  # verify compile_commands.json has been generated
  ls -l compile_commands.json
  cat compile_commands.json
```

Alternatively, a program called `bear` can also be used to create `compile_commands.json`, regardless of the C++ build system you are using. It does this by intercepting subsequent command-line commands and collecting all C++ compilation flags passed to the compiler.  To use this approach, prepend `bear --` at the beginning of the build command.   For CMake, you can do:

``` bash
# build compile_commands.json from scratch
  bear -- cmake --build build/ --clean-first
# or, update the existing compile_commands.json
  bear --append -- cmake --build build/
```

Either way, this should produce the `compile_commands.json` file.  Now, you can use it with the IDE.

### Visual studio code
1. Open `cpp-boilerplate-v2/app/main.cpp`

1. Move the cursor to the `dummy()` function call and press the F12 key (or right-click->Go to Definition).  Visual studio code should automatically open `cpp-boilerplate-v2/include/lib.hpp` and place the curse at line 5, where the `dummy` function is defined.

1. Close the editor, delete the `compile_commands.json` file and repeat.  Verify that *step 2 does not work anymore*.

### Emacs

1. Open `cpp-boilerplate-v2/app/main.cpp` and start `eglot` if it's not already running.

1. Move the cursor to the `dummy()` function call and press the `<M-.>` key (or xref-find-definitions).  Emacs should automatically open `cpp-boilerplate-v2/include/lib.hpp` and place the curse at line 5, where the `dummy` function is defined.

1. Close the editor, delete the `compile_commands.json` file and repeat.  Verify that *step 2 does not work anymore*.
