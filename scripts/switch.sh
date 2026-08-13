#!/usr/bin/env bash
# Switch which problem main.cpp includes and runs.
# Usage: scripts/switch.sh <problem-number>
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <problem-number>" >&2
    exit 1
fi

n="$1"
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

match=$(find "$root/problems" -name "${n}*.cpp" | sort | head -1)
if [ -z "$match" ]; then
    echo "No problems/${n}*.cpp found" >&2
    exit 1
fi

rel="${match#$root/}"

cat > "$root/main.cpp" <<EOF
// ─────────────────────────────────────────────────────────────────────────────
//  To switch problems: run \`scripts/switch.sh <problem-number>\`, or change the
//  #include below by hand. Each problems/*.cpp file defines its own run()
//  wiring up runTests() with the right parsers — nothing else needs editing.
// ─────────────────────────────────────────────────────────────────────────────
#include "runner.h"
#include "${rel}"

int main() {
    run();
    return 0;
}
EOF

echo "main.cpp now includes ${rel}"
