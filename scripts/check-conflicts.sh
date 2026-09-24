#!/usr/bin/env bash
# Fail if any tracked file contains literal, unresolved git merge-conflict
# markers. This repo has had these accidentally committed before (a botched
# `git stash pop` left them in place instead of being resolved) -- this
# catches that class of mistake before it lands.
#
# Usage: scripts/check-conflicts.sh
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

# Excludes this script itself, since the pattern below necessarily contains
# the literal marker text.
if git grep -nE '^<<<<<<< |^=======$|^>>>>>>> ' -- . ':(exclude)scripts/check-conflicts.sh'; then
  echo "Found unresolved merge-conflict markers in the files above." >&2
  exit 1
fi

echo "No conflict markers found."
