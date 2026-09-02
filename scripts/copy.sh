#!/usr/bin/env bash
# Copy the LeetCode-submittable solution file to the clipboard. Since
# problems/<bucket>/<n>.cpp (and contests/.../Qn.cpp) files contain nothing
# but the solution itself -- no runner.h, no run() -- this just needs to
# find the right file and cat it, no extraction required.
# Usage: scripts/copy.sh [problem-number]
# With no argument, resolves the solution file from whatever harness
# main.cpp currently includes (tests/<bucket>/<n>/run.cpp or
# contests/.../tests/<Q>/run.cpp).
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
    harness_rel=$(grep -oE '#include "(tests|contests)/[^"]+/run\.cpp"' "$root/main.cpp" | sed -E 's/#include "(.*)"/\1/')
    if [ -z "$harness_rel" ]; then
        echo "Could not resolve the active harness from main.cpp" >&2
        exit 1
    fi
    solution_rel=$(grep -oE '#include "(problems|contests)/[^"]+\.cpp"' "$root/$harness_rel" | sed -E 's/#include "(.*)"/\1/')
    if [ -z "$solution_rel" ]; then
        echo "Could not resolve the solution file from ${harness_rel}" >&2
        exit 1
    fi
    match="$root/$solution_rel"
fi

output=$(cat "$match")

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
