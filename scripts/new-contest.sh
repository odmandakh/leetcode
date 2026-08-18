#!/usr/bin/env bash
# Scaffold a new contest: creates contests/<Type>/<number>/Q1..Qn.cpp +
# contests/<Type>/<number>/tests/Q1..Qn/, then switches to Q1.
# Usage: scripts/new-contest.sh
# Prompts interactively for contest type (Weekly/Biweekly), number,
# number of questions (blank defaults to 4), and number of test cases
# per question (blank defaults to 3) -- creates that many empty
# <k>.in/<k>.out placeholder pairs per question.
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

PS3="Contest type: "
select type in "Weekly Contest" "Biweekly Contest"; do
    case "$type" in
    "Weekly Contest" | "Biweekly Contest") break ;;
    *) echo "Invalid selection, try again." >&2 ;;
    esac
done

read -rp "Contest number: " number
if ! [[ "$number" =~ ^[0-9]+$ ]]; then
    echo "Contest number must be a positive integer" >&2
    exit 1
fi

read -rp "Number of questions [4]: " numQ
numQ="${numQ:-4}"
if ! [[ "$numQ" =~ ^[0-9]+$ ]] || [ "$numQ" -eq 0 ]; then
    echo "Number of questions must be a positive integer" >&2
    exit 1
fi

read -rp "Number of test cases per question [3]: " numTests
numTests="${numTests:-3}"
if ! [[ "$numTests" =~ ^[0-9]+$ ]] || [ "$numTests" -eq 0 ]; then
    echo "Number of test cases must be a positive integer" >&2
    exit 1
fi

contest="${type}/${number}"
contestDir="$root/contests/${contest}"
if [ -e "$contestDir" ]; then
    echo "contests/${contest} already exists" >&2
    exit 1
fi

mkdir -p "$contestDir"

for ((i = 1; i <= numQ; i++)); do
    mkdir -p "$contestDir/tests/Q${i}"
    for ((t = 1; t <= numTests; t++)); do
        : >"$contestDir/tests/Q${i}/${t}.in"
        : >"$contestDir/tests/Q${i}/${t}.out"
    done
    cat >"$contestDir/Q${i}.cpp" <<EOF
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
      "${type} ${number} - Q${i}",
      Parse::intVec,                              // TODO: pick parser
      Parse::intVec,                              // TODO: pick parser
      [](auto d) { return Solution().TODO(d); }   // TODO: solve
  );
}
EOF
done

echo "Created contests/${contest}/ with Q1..Q${numQ}.cpp and tests/Q1..Q${numQ}/ (${numTests} empty .in/.out pair(s) each)"

rel="contests/${contest}/Q1.cpp"
cat > "$root/main.cpp" <<EOF
// ─────────────────────────────────────────────────────────────────────────────
//  To switch problems: run \`scripts/switch.sh <problem-number>\`, or for a
//  contest problem run \`scripts/switch-contest.sh\` (interactive menu), or
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
