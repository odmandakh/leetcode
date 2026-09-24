#!/usr/bin/env bash
# Build + run every solved problem's and contest question's own tests,
# one at a time (switching main.cpp to each in turn), restoring whatever
# main.cpp pointed at before this script ran.
#
# Useful after touching a shared file (runner.h, CMakeLists.txt, or any of
# the scripts/*.sh main.cpp templates) to make sure nothing broke elsewhere --
# ./build/LeetCode alone only ever checks whichever one problem is "active".
#
# Usage: scripts/test-all.sh
set -uo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

[ -d build ] || cmake -S . -B build >/dev/null

orig_main="$(mktemp)"
cp main.cpp "$orig_main"
trap 'cp "$orig_main" main.cpp; rm -f "$orig_main"' EXIT

declare -a build_fail=()
declare -a test_fail=()
declare -a skipped_unsolved=()
ok=0
total=0

echo "=== Problems ==="
while IFS= read -r f; do
  n="$(basename "$f" .cpp)"
  bucket="$(basename "$(dirname "$f")")"
  testdir="$root/tests/$bucket/$n"
  [ -d "$testdir" ] || continue
  # Not yet hand-wired at all -- a genuinely unstarted problem, not a
  # regression. Skip rather than fail so in-progress work doesn't
  # permanently redden the check.
  if grep -q "// TODO: implement" "$f"; then
    skipped_unsolved+=("$n")
    continue
  fi
  total=$((total + 1))
  if ! scripts/switch.sh "$n" >/dev/null 2>&1; then
    build_fail+=("$n (switch failed)")
    echo "  [SWITCH FAIL] $n"
    continue
  fi
  rm -f build/CMakeFiles/LeetCode.dir/main.cpp.o
  if ! cmake --build build -j4 >"/tmp/test-all-build-${n}.log" 2>&1; then
    build_fail+=("$n")
    echo "  [BUILD FAIL] $n"
    continue
  fi
  if ! ./build/LeetCode >"/tmp/test-all-run-${n}.log" 2>&1; then
    test_fail+=("$n")
    echo "  [TEST FAIL]  $n"
  else
    ok=$((ok + 1))
  fi
done < <(find "$root/problems" -name "*.cpp" | sort)

echo "=== Contests ==="
while IFS= read -r qfile; do
  qdir="$(dirname "$qfile")"     # .../contests/<Type>/<number>
  q="$(basename "$qfile" .cpp)"  # Q1, Q2, ...
  testdir="$qdir/tests/$q"
  [ -d "$testdir" ] || continue
  rel="${qdir#$root/}/tests/$q/run.cpp"
  if grep -q "// TODO: implement" "$qfile"; then
    skipped_unsolved+=("${rel#contests/}")
    continue
  fi
  label="${rel#contests/}"
  logname="$(echo "$label" | tr '/ ' '__')"
  total=$((total + 1))
  cat >"$root/main.cpp" <<EOF
#include "runner.h"
#include "${rel}"

int main() {
    run();
    return TestStatus::allPassed ? 0 : 1;
}
EOF
  rm -f build/CMakeFiles/LeetCode.dir/main.cpp.o
  if ! cmake --build build -j4 >"/tmp/test-all-build-contest-${logname}.log" 2>&1; then
    build_fail+=("$label")
    echo "  [BUILD FAIL] $label"
    continue
  fi
  if ! ./build/LeetCode >"/tmp/test-all-run-contest-${logname}.log" 2>&1; then
    test_fail+=("$label")
    echo "  [TEST FAIL]  $label"
  else
    ok=$((ok + 1))
  fi
done < <(find "$root/contests" -name "Q*.cpp" | sort)

echo
echo "=== Summary ==="
echo "Total checked: $total"
echo "OK: $ok"
echo "Skipped (unsolved, not hand-wired yet) (${#skipped_unsolved[@]}): ${skipped_unsolved[*]:-none}"
echo "Build failures (${#build_fail[@]}): ${build_fail[*]:-none}"
echo "Test failures (${#test_fail[@]}): ${test_fail[*]:-none}"

if [ "${#build_fail[@]}" -gt 0 ] || [ "${#test_fail[@]}" -gt 0 ]; then
  exit 1
fi
exit 0
