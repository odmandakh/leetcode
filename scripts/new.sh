#!/usr/bin/env bash
# Scaffold a new problem: creates problems/<n>.cpp + tests/<n>/, then switches to it.
# Usage: scripts/new.sh <problem-number> ["<Title>"]
set -euo pipefail

if [ $# -lt 1 ]; then
    echo "Usage: $0 <problem-number> [\"<Title>\"]" >&2
    exit 1
fi

n="$1"
title="${2:-Problem $n}"
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
file="$root/problems/${n}.cpp"

if [ -e "$file" ]; then
    echo "problems/${n}.cpp already exists" >&2
    exit 1
fi

mkdir -p "$root/tests/${n}"

cat > "$file" <<EOF
#include "runner.h"
#include <vector>

class Solution {
public:
    // TODO: implement
};

inline void run() {
    runTests(
        std::string(PROJECT_ROOT) + "/tests/${n}",
        "${title}",
        Parse::intVec,                              // TODO: pick parser
        Parse::intVec,                              // TODO: pick parser
        [](auto d) { return Solution().TODO(d); }   // TODO: solve
    );
}
EOF

echo "Created problems/${n}.cpp and tests/${n}/"
"$root/scripts/switch.sh" "$n"
