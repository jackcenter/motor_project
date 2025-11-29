#!/usr/bin/env bash
BUILD_DIR="build"
BIN_DIR="bin"
EXECUTABLE="motor_project"

set -e

ROOT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_PATH="$ROOT_PATH/$BUILD_DIR/$BIN_DIR"


if [ ! -x "$BIN_PATH/$EXECUTABLE" ]; then
    echo "Executable $EXECUTABLE not found. Did you run build.sh?"
    exit 1
fi
"$BIN_PATH/$EXECUTABLE"
