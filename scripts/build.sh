#!/usr/bin/env bash
BUILD_DIR="build"

set -e

ROOT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_PATH="$ROOT_PATH/$BUILD_DIR"

cmake -S "$ROOT_PATH" -B "$BUILD_PATH"
cmake --build "$BUILD_PATH"
