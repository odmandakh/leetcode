#!/usr/bin/env bash
# Checks clang-format compliance (against .clang-format) for changed C++
# files only -- new/touched code gets checked, already-solved problems
# aren't retroactively flagged just for predating this check.
#
# Usage: scripts/check-format.sh [base-ref]
#   base-ref defaults to HEAD~1 (previous commit). In CI this is passed
#   explicitly: the base branch for a pull_request, or the pre-push commit
#   for a direct push.
set -uo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

if ! command -v clang-format >/dev/null 2>&1; then
  echo "clang-format not found -- install it to run this check." >&2
  exit 1
fi

base="${1:-HEAD~1}"

if ! git rev-parse --verify "$base" >/dev/null 2>&1; then
  echo "Base ref '$base' not found (e.g. first commit on a new branch) -- nothing to diff, skipping."
  exit 0
fi

found=0
fail=0
while IFS= read -r f; do
  [ -n "$f" ] || continue
  found=1
  [ -f "$f" ] || continue
  if ! clang-format --dry-run --Werror -style=file "$f"; then
    echo "  [FORMAT FAIL] $f"
    fail=1
  fi
done < <(git diff --name-only --diff-filter=ACMR "$base"...HEAD -- '*.cpp' '*.h' 2>/dev/null)

if [ "$found" -eq 0 ]; then
  echo "No changed C++ files to check."
  exit 0
fi

if [ "$fail" -ne 0 ]; then
  echo
  echo "Some files aren't clang-format-clean. Fix with: clang-format -i <file>"
  exit 1
fi

echo "All changed C++ files are clang-format-clean."
