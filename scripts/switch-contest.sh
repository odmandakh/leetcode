#!/usr/bin/env bash
# Switch which contest question main.cpp includes and runs.
# Usage: scripts/switch-contest.sh
# Prompts interactively: contest type (menu) -> contest number (typed) ->
# question (menu, built from what actually exists under contests/).
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

PS3="Contest type: "
select type in "Weekly Contest" "Biweekly Contest"; do
    case "$type" in
    "Weekly Contest" | "Biweekly Contest") break ;;
    *) echo "Invalid selection, try again." >&2 ;;
    esac
done

typeDir="$root/contests/${type}"

read -rp "Contest number: " number
if ! [[ "$number" =~ ^[0-9]+$ ]]; then
    echo "Contest number must be a positive integer" >&2
    exit 1
fi

contestDir="$typeDir/$number"
if [ ! -d "$contestDir" ]; then
    echo "No contests/${type}/${number} found -- run scripts/new-contest.sh first" >&2
    exit 1
fi
questions=()
while IFS= read -r f; do
    questions+=("$(basename "$f" .cpp)")
done < <(find "$contestDir" -maxdepth 1 -name "Q*.cpp" | sort -V)

if [ ${#questions[@]} -eq 0 ]; then
    echo "No Qn.cpp files found under contests/${type}/${number}" >&2
    exit 1
fi

PS3="Question: "
select q in "${questions[@]}"; do
    [ -n "${q:-}" ] && break
    echo "Invalid selection, try again." >&2
done

match="$contestDir/$q.cpp"
rel="${match#$root/}"

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
