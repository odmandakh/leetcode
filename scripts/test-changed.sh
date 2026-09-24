#!/usr/bin/env bash
# Build + run only the problems / contest questions whose own files changed
# (solution, harness, or fixtures) since <base-ref>. Fast check for normal
# day-to-day pushes. After touching shared files (runner.h, CMakeLists.txt,
# scripts/*.sh) run scripts/test-all.sh instead (manual CI job or locally).
#
# Usage: scripts/test-changed.sh [base-ref]   (default: HEAD~1)
set -o pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

base="${1:-HEAD~1}"
if ! git rev-parse --verify "$base" >/dev/null 2>&1; then
  echo "Base ref '$base' not found (e.g. first commit on a new branch) -- nothing to diff, skipping."
  exit 0
fi

[ -d build ] || cmake -S . -B build >/dev/null

# Map each changed file to a target: "P <bucket>/<n>" or "C <Type>/<number>/<Qn>".
# (A function, not inline in $(...): bash 3.2 can't parse `case` inside $( ).)
map_changed() {
  local f a b c d e g
  while IFS= read -r f; do
    IFS=/ read -r a b c d e g <<<"$f"
    case "$a" in
      problems) [ -n "$c" ] && echo "P $b/${c%.cpp}" ;;
      tests) [ -n "$d" ] && echo "P $b/$c" ;;
      contests)
        if [ "${d%.cpp}" != "$d" ]; then
          echo "C $b/$c/${d%.cpp}"
        elif [ "$d" = "tests" ] && [ -n "$g" ]; then
          echo "C $b/$c/$e"
        fi
        ;;
    esac
  done
}

targets="$(git diff --name-only --diff-filter=ACMR "$base"...HEAD -- problems tests contests | map_changed | sort -u)"

if [ -z "$targets" ]; then
  echo "No problem/contest files changed -- nothing to test."
  echo "(If you changed runner.h, CMakeLists.txt or scripts/*.sh, run scripts/test-all.sh.)"
  exit 0
fi

orig_main="$(mktemp)"
cp main.cpp "$orig_main"
trap 'cp "$orig_main" main.cpp; rm -f "$orig_main"' EXIT

build_fail=""
test_fail=""
skipped=""
ok=0
total=0

run_one() { # $1=label $2=harness-rel $3=solution-file
  local label="$1" rel="$2" sol="$3" log
  log="/tmp/test-changed-$(echo "$label" | tr '/ ' '__')"
  if [ ! -f "$sol" ] || [ ! -f "$root/$rel" ]; then
    echo "-- $label: solution or harness missing, skipping --"
    skipped="$skipped $label"
    return
  fi
  if grep -q "// TODO: implement" "$sol"; then
    echo "-- $label: unsolved stub, skipping --"
    skipped="$skipped $label"
    return
  fi
  total=$((total + 1))
  echo "-- Testing $label --"
  cat >"$root/main.cpp" <<EOF
#include "runner.h"
#include "${rel}"

int main() {
  run();
  return TestStatus::allPassed ? 0 : 1;
}
EOF
  rm -f build/CMakeFiles/LeetCode.dir/main.cpp.o
  if ! cmake --build build -j4 >"$log-build.log" 2>&1; then
    build_fail="$build_fail $label"
    echo "  [BUILD FAIL] $label"
    cat "$log-build.log"
    return
  fi
  if ! ./build/LeetCode >"$log-run.log" 2>&1; then
    test_fail="$test_fail $label"
    echo "  [TEST FAIL]  $label"
    cat "$log-run.log"
  else
    ok=$((ok + 1))
  fi
}

while IFS= read -r t; do
  kind="${t%% *}"
  path="${t#* }"
  if [ "$kind" = "P" ]; then
    bucket="${path%/*}"
    n="${path#*/}"
    run_one "$n" "tests/$bucket/$n/run.cpp" "problems/$bucket/$n.cpp"
  else
    dir="${path%/*}" # <Type>/<number>
    q="${path##*/}"
    run_one "$path" "contests/$dir/tests/$q/run.cpp" "contests/$dir/$q.cpp"
  fi
done <<<"$targets"

echo
echo "=== Summary ==="
echo "Checked: $total   OK: $ok"
echo "Skipped:${skipped:- none}"
echo "Build failures:${build_fail:- none}"
echo "Test failures:${test_fail:- none}"

[ -z "$build_fail" ] && [ -z "$test_fail" ]
