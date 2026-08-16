#!/usr/bin/env bash
# Scaffold a new contest: creates contests/<Contest Name>/Q1..Qn.cpp +
# contests/<Contest Name>/tests/Q1..Qn/, then switches to Q1.
# Usage: scripts/new-contest.sh "<Contest Name>" [num_questions]
set -euo pipefail

if [ $# -lt 1 ]; then
    echo "Usage: $0 \"<Contest Name>\" [num_questions]" >&2
    exit 1
fi

contest="$1"
numQ="${2:-4}"
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

contestDir="$root/contests/${contest}"
if [ -e "$contestDir" ]; then
    echo "contests/${contest} already exists" >&2
    exit 1
fi

mkdir -p "$contestDir"

for ((i = 1; i <= numQ; i++)); do
    mkdir -p "$contestDir/tests/Q${i}"
    cat > "$contestDir/Q${i}.cpp" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  // TODO: implement
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/${contest}/tests/Q${i}",
      "${contest} - Q${i}",
      Parse::intVec,                              // TODO: pick parser
      Parse::intVec,                              // TODO: pick parser
      [](auto d) { return Solution().TODO(d); }   // TODO: solve
  );
}
EOF
done

echo "Created contests/${contest}/ with Q1..Q${numQ}.cpp and tests/Q1..Q${numQ}/"
"$root/scripts/switch.sh" "$contest" 1
