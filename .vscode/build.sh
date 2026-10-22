#!/usr/bin/env bash
# Usage: bash build.sh <file.cpp> <workspace_root> [--run]
file="$1"
run="$3"

# bin is always created in the same folder as the .cpp file
dir="$(dirname "$file")"
mkdir -p "$dir/bin"

name="$(basename "$file" .cpp)"
out="$dir/bin/$name"

if g++ -fdiagnostics-color=always -g "$file" -o "$out"; then
    echo "Success -> $out"
    if [ "$run" = "--run" ]; then
        "$out"
    fi
else
    exit 1
fi