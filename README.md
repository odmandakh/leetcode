# leetcode
LeetCode problem solving with a consistent learning loop.

## Build & Run
One-time setup:
```bash
brew install cmake      # if not already installed
cmake -S . -B build
```

Build and run the currently active problem:
```bash
cmake --build build
./build/LeetCode
```
This runs every `.in`/`.out` case under the active problem's `tests/<bucket>/<n>/` directory and prints PASS/FAIL (with timing) per case.

## Switching Problems
Only one problem is "active" (included by `main.cpp`) at a time. Each `problems/<n>.cpp` owns its own `Solution` class *and* the `run()` call that wires it up to `runTests()` — so switching never touches `CMakeLists.txt` and can't mismatch a parser to the wrong problem.

Problem files live in number-range subfolders — `problems/0-999/`, `problems/1000-1999/`, `problems/2000-2999/`, `problems/3000-3999/`, etc. — instead of one flat directory, to keep things browsable as the collection grows. `tests/` mirrors the exact same buckets (`tests/2000-2999/2161/` matches `problems/2000-2999/2161.cpp`). `scripts/new.sh`/`scripts/switch.sh` compute the right bucket automatically; you never need to pick one by hand.

- **Switch to an already-solved problem:**
  ```bash
  scripts/switch.sh <problem-number>   # e.g. scripts/switch.sh 66
  cmake --build build && ./build/LeetCode
  ```
- **Start a brand-new problem:**
  ```bash
  scripts/new.sh <problem-number> "<Title>" [shape] [methodName]
  # e.g. scripts/new.sh 217 "Contains Duplicate"                    (generic TODO stub)
  # e.g. scripts/new.sh 2958 "Longest Subarray With K Frequency" vec-int-scalar maxSubarrayLength
  ```
  This scaffolds `problems/<bucket>/<n>.cpp` and an empty `tests/<bucket>/<n>/` directory, then switches `main.cpp` to point at it.

  If you pass a `shape` + `methodName`, the generated `run()` is **fully wired** — no "TODO: pick parser" guessing, no wrong-arity bugs. `scripts/new.sh` (no args) prints the current shape table; the shapes cover every signature this repo has needed so far:

  | shape | `Solution` signature |
  |---|---|
  | `vec` | `vector<int> f(vector<int>&)` → `vector<int>` |
  | `vec-scalar` | `int f(vector<int>&)` → `int` |
  | `vec-int` | `vector<int> f(vector<int>&, int)` → `vector<int>` |
  | `vec-int-scalar` | `int f(vector<int>&, int)` → `int` |
  | `matrix` | `vector<int> f(vector<vector<int>>&)` → `vector<int>` |
  | `str-scalar-str` | `string f(string, long long)` → `string` |
  | `str-query` | `vector<int> f(string, string, vector<int>&)` → `vector<int>` |

  Omit `shape`/`methodName` for anything else (falls back to the generic TODO stub, same as before) — e.g. `problems/3000-3999/3161.cpp`'s query-array signature is bespoke enough it's still hand-wired.

  **Test fixture convention:** one field per line — arrays bracketed (`[1,2,3]`), scalars plain (`2`). This matches copy-pasting LeetCode's own `Input: nums = [...], k = ...` / `Output: ...` text directly, split at the commas, no reformatting needed. (Arrays must be alone on their line — the bracketed parsers consume every number on the line they're given.)

## Workflow
- Use `cpp-pro` for C++ implementation, debugging, and performance improvements.
- Use `leetcode-teacher` to explain patterns, invariants, and interview-ready reasoning.

## Daily Loop (30-60 min)
1. Pick one problem, run `scripts/new.sh <n> "<Title>"`, and write edge cases as `.in`/`.out` files in `tests/<bucket>/<n>/` first.
2. Solve it in `problems/<n>.cpp` without help for 15-25 minutes.
3. Ask `cpp-pro` for correctness/performance review.
4. Ask `leetcode-teacher` for pattern recap and reuse rules.

If you end up asking for the solution outright instead of solving it independently, mark the file honestly — add `// ASSISTED: <short reason>` right above `class Solution`. It's grep-able later: `grep -rl ASSISTED problems/` lists every problem that needs a solo re-attempt.

## Practice Log Template
Copy this block per problem:

```markdown
### YYYY-MM-DD - <Problem Name>
- Difficulty: Easy | Medium | Hard
- Time Spent: <minutes>
- Pattern: <two pointers / stack / DP / ...>
- Mistake I Made: <what went wrong>
- Key Invariant: <why this works>
- Complexity: O(?) time, O(?) space
- Next Drill: <related problem to reinforce>
```
