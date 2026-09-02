#!/usr/bin/env bash
# Extract the LeetCode-submittable portion of a problem file -- everything
# before `inline void run()`, with the `#include "runner.h"` line dropped
# (LeetCode's judge has no such header) -- and copy it to the clipboard.
# Usage: scripts/copy.sh [problem-number]
# With no argument, uses whatever main.cpp currently includes.
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

if [ $# -eq 1 ]; then
    n="$1"
    match=$(find "$root/problems" -name "${n}*.cpp" | sort | head -1)
    if [ -z "$match" ]; then
        echo "No problems/${n}*.cpp found" >&2
        exit 1
    fi
else
    rel=$(grep -oE '#include "(problems|contests)/[^"]+\.cpp"' "$root/main.cpp" | sed -E 's/#include "(.*)"/\1/')
    if [ -z "$rel" ]; then
        echo "Could not resolve the active file from main.cpp" >&2
        exit 1
    fi
    match="$root/$rel"
fi

output=$(awk '/^inline void run\(\)/{exit} {print}' "$match" | grep -v '#include "runner.h"')

echo "$output"

if command -v pbcopy >/dev/null 2>&1; then
    printf '%s\n' "$output" | pbcopy
    echo "--- copied to clipboard (pbcopy) ---" >&2
elif command -v xclip >/dev/null 2>&1; then
    printf '%s\n' "$output" | xclip -selection clipboard
    echo "--- copied to clipboard (xclip) ---" >&2
elif command -v clip.exe >/dev/null 2>&1; then
    printf '%s\n' "$output" | clip.exe
    echo "--- copied to clipboard (clip.exe) ---" >&2
else
    echo "--- no clipboard tool found (pbcopy/xclip/clip.exe); printed above only ---" >&2
fi
