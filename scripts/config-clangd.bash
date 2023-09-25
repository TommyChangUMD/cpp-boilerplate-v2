#!/usr/bin/bash

#
# Exit immediately if any subsequent command fails
#
set -o errexit
set -o nounset
set -o pipefail

#
# Create the cland config file
#
echo "creating ~/.config/clangd/config.yaml"

mkdir -p ~/.config/clangd

cat << "EOF" > ~/.config/clangd/config.yaml
Diagnostics:
  UnusedIncludes: Strict

CompileFlags:
  # Treat code as C++, use C++17 standard, enable more warnings.
  # Add: [-xc++, -std=c++17, -Wall, -Wno-missing-prototypes]
  Add: [-std=c++17]

  # Get rid of error [drv_unknown_argument]: Unknown argument: '-fprofile-abs-path'
  Remove: [-fprofile-abs-path]
EOF

echo "done!"
