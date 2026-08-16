#!/usr/bin/env bash
# Switch which problem main.cpp includes and runs.
# Usage: scripts/switch.sh <problem-number>
#        scripts/switch.sh "<Contest Name>" <Qn>
set -euo pipefail

if [ $# -eq 1 ]; then
    n="$1"
    root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

    match=$(find "$root/problems" -name "${n}*.cpp" | sort | head -1)
    if [ -z "$match" ]; then
        echo "No problems/${n}*.cpp found" >&2
        exit 1
    fi
elif [ $# -eq 2 ]; then
    contest="$1"
    q="$2"
    root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

    match="$root/contests/${contest}/Q${q}.cpp"
    if [ ! -e "$match" ]; then
        echo "No contests/${contest}/Q${q}.cpp found" >&2
        exit 1
    fi
else
    echo "Usage: $0 <problem-number>" >&2
    echo "       $0 \"<Contest Name>\" <Qn>" >&2
    exit 1
fi

rel="${match#$root/}"

cat > "$root/main.cpp" <<EOF
// ─────────────────────────────────────────────────────────────────────────────
//  To switch problems: run \`scripts/switch.sh <problem-number>\` (or
//  \`scripts/switch.sh "<Contest Name>" <Qn>\` for a contest problem), or
//  change the #include below by hand. Each problems/*.cpp / contests/*/Qn.cpp
//  file defines its own run() wiring up runTests() -- nothing else needs editing.
// ─────────────────────────────────────────────────────────────────────────────
#include "runner.h"
#include "${rel}"

int main() {
    run();
    return 0;
}
EOF

echo "main.cpp now includes ${rel}"
