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

solution=$(find "$root/problems" -name "${n}*.cpp" | sort | head -1)
if [ -z "$solution" ]; then
    echo "No problems/${n}*.cpp found" >&2
    exit 1
fi

# The harness (run() + parser wiring) lives beside that problem's test
# fixtures, not in problems/ itself -- see tests/<bucket>/<n>/run.cpp.
harness=$(find "$root/tests" -path "*/${n}/run.cpp" | sort | head -1)
if [ -z "$harness" ]; then
    echo "Found problems/${n}*.cpp but no matching tests/*/${n}/run.cpp harness" >&2
    echo "(run scripts/new.sh for a fresh problem, or migrate this one to the new layout)" >&2
    exit 1
fi

rel="${harness#$root/}"

cat > "$root/main.cpp" <<EOF
// ─────────────────────────────────────────────────────────────────────────────
//  To switch problems: run \`scripts/switch.sh <problem-number>\`, or for a
//  contest problem run \`scripts/switch-contest.sh\` (interactive menu), or
//  change the #include below by hand. Each problems/*.cpp / contests/*/Qn.cpp
//  file is the LeetCode-submittable solution only; its matching
//  tests/<bucket>/<n>/run.cpp (or contests/.../tests/<Q>/run.cpp) defines
//  run() wiring up runTests() -- nothing else needs editing.
// ─────────────────────────────────────────────────────────────────────────────
#include "runner.h"
#include "${rel}"

int main() {
    run();
    return 0;
}
EOF

echo "main.cpp now includes ${rel}"
