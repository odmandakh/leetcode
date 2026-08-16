#!/usr/bin/env bash
# Scaffold a new contest: creates contests/<Type>/<number>/Q1..Qn.cpp +
# contests/<Type>/<number>/tests/Q1..Qn/, then switches to Q1.
# Usage: scripts/new-contest.sh
# Prompts interactively for contest type (Weekly/Biweekly), number, and
# number of questions (blank defaults to 4).
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

contest="${type}/${number}"
contestDir="$root/contests/${contest}"
if [ -e "$contestDir" ]; then
    echo "contests/${contest} already exists" >&2
    exit 1
fi

mkdir -p "$contestDir"

for ((i = 1; i <= numQ; i++)); do
    mkdir -p "$contestDir/tests/Q${i}"
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

echo "Created contests/${contest}/ with Q1..Q${numQ}.cpp and tests/Q1..Q${numQ}/"
"$root/scripts/switch.sh" "$contest" 1
