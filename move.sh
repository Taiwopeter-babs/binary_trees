#!/usr/bin/env bash
# This script moves all files without an extension to targetted directory
find . -maxdepth 1 -type f ! -name "*.*" -exec mv -t "$1" {} \+
