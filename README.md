# cpp-boilerplate-v2

<!-- # C++ Boilerplate Badges -->
<!-- [![Build Status](https://github.com/TommyChangUMD/cpp-boilerplate/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/TommyChangUMD/cpp-boilerplate/actions/workflows/build_and_coveralls.yml) -->

<!-- [![Coverage Status](https://coveralls.io/repos/github/TommyChangUMD/cpp-boilerplate/badge.svg?branch=master)](https://coveralls.io/github/TommyChangUMD/cpp-boilerplate?branch=master) -->


## Overview

Simple starter C++ project with:

- CMake
- GoogleTest

## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/TommyChangUMD/cpp-boilerplate-v2 
  cd cpp-boilerplate-v2 
# Create make files:
  cmake -S ./ -B build/
# Compile and build the code:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
# Run program: 
  ./build/app/shell-app
# Run tests: 
  ctest --test-dir build/
# Run clean and start over: 
  rm -rf build/
```

<!-- ## Building for code coverage (for assignments beginning in Week 4) -->
<!-- ``` -->
<!-- sudo apt-get install lcov -->
<!-- cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../ -->
<!-- make -->
<!-- make code_coverage -->
<!-- ``` -->
<!-- This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser. -->


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

However, for clangd to work properly, it must ab able to find a file called `compile_commands.json` somewhere in your source code tree.  There are many ways to generate this compilation database file.  CMake can generate it for you if you enable the `CMAKE_EXPORT_COMPILE_COMMANDS` option.  To enable it, put the line below in your top-level `CMakeLists.txt` file:

``` cmake
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
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
