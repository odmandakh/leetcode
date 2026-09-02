# Leetcode
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
Only one problem is "active" (included by `main.cpp`) at a time. Each problem is split across two files: `problems/<bucket>/<n>.cpp` holds *only* the `Solution` class — nothing else, so it's directly LeetCode-submittable as-is (see "Copying a Solution to LeetCode" below) — and `tests/<bucket>/<n>/run.cpp` holds the `run()` call that includes it and wires it up to `runTests()`. `main.cpp` always includes the `run.cpp` harness, never the solution file directly. Switching never touches `CMakeLists.txt` and can't mismatch a parser to the wrong problem.

Problem files live in number-range subfolders — `problems/0-999/`, `problems/1000-1999/`, `problems/2000-2999/`, `problems/3000-3999/`, etc. — instead of one flat directory, to keep things browsable as the collection grows. `tests/` mirrors the exact same buckets (`tests/2000-2999/2161/run.cpp` is the harness for `problems/2000-2999/2161.cpp`). `scripts/new.sh`/`scripts/switch.sh` compute the right bucket and write/find both files automatically; you never need to pick one by hand.

- **Switch to an already-solved problem:**
  ```bash
  scripts/switch.sh <problem-number>   # e.g. scripts/switch.sh 66
  cmake --build build && ./build/LeetCode
  ```
- **Start a brand-new problem:**
  ```bash
  scripts/new.sh <problem-number> "<Title>" [shape] [methodName] [--tests N]
  # e.g. scripts/new.sh 217 "Contains Duplicate"                    (generic TODO stub)
  # e.g. scripts/new.sh 2958 "Longest Subarray With K Frequency" vec-int-scalar maxSubarrayLength
  # e.g. scripts/new.sh 42 "Trapping Rain Water" vec-scalar trap --tests 5
  ```
  This scaffolds `problems/<bucket>/<n>.cpp` (the solution file) and a `tests/<bucket>/<n>/` directory containing `run.cpp` (the harness) plus empty `1.in`/`1.out`, `2.in`/`2.out`, `3.in`/`3.out` placeholder pairs (ready to paste LeetCode's examples into), then switches `main.cpp` to point at the harness. `--tests N` (or `-t N`) changes how many pairs get created — it's a flag, not a positional arg, so it works whether or not you also pass `shape`/`methodName`, and can go anywhere on the command line. Defaults to 3 if omitted.

  If you pass a `shape` + `methodName`, the generated `run()` is **fully wired** — no "TODO: pick parser" guessing, no wrong-arity bugs. `scripts/new.sh` (no args) prints the current shape table; the shapes cover every signature this repo has needed so far:

  | shape | `Solution` signature |
  |---|---|
  | `vec` | `vector<int> f(vector<int>&)` → `vector<int>` |
  | `vec-scalar` | `int f(vector<int>&)` → `int` |
  | `vec-int` | `vector<int> f(vector<int>&, int)` → `vector<int>` |
  | `vec-int-scalar` | `int f(vector<int>&, int)` → `int` |
  | `matrix` | `vector<int> f(vector<vector<int>>&)` → `vector<int>` |
  | `scalar` | `int f(int)` → `int` |
  | `two-scalar` | `int f(int, int)` → `int` |
  | `scalar-vec` | `vector<int> f(int)` → `vector<int>` |
  | `scalar-matrix` | `vector<vector<int>> f(int)` → `vector<vector<int>>` |
  | `scalar-bool` | `bool f(int)` → `bool` (`true`/`false`) |
  | `scalar-vec-scalar` | `int f(int, vector<int>&)` → `int` |
  | `matrix-vec-scalar` | `int f(vector<vector<int>>&, vector<int>&)` → `int` |
  | `str-scalar-str` | `string f(string, long long)` → `string` |
  | `str-scalar` | `int f(string)` → `int` (quotes stripped) |
  | `two-str-scalar` | `int f(string, string)` → `int` (quotes stripped) |
  | `str-query` | `vector<int> f(string, string, vector<int>&)` → `vector<int>` |

  Omit `shape`/`methodName` for anything else (falls back to the generic TODO stub, same as before) — e.g. `problems/3000-3999/3161.cpp`'s query-array signature is bespoke enough it's still hand-wired.

  **Test fixture convention:** one field per line — arrays bracketed (`[1,2,3]`), scalars plain (`2`), strings quoted (`"abc"` or `'abc'`). This matches copy-pasting LeetCode's own `Input: nums = [...], k = ...` / `Output: ...` text directly, split at the commas, no reformatting needed. (Arrays must be alone on their line — the bracketed parsers consume every number on the line they're given.) String shapes use `Parse::quotedString`/`Parse::stripQuotes` (in `runner.h`), which strip one layer of surrounding `"..."` or `'...'` quotes, so quoted LeetCode string inputs work with no manual stripping.

## Contests
Live LeetCode contests (Weekly/Biweekly) present 4 problems at once, identified by contest type + number + question number rather than a LeetCode problem number — so they live in their own `contests/` tree instead of `problems/`/`tests/`, grouped first by type (`Weekly Contest`/`Biweekly Contest`), then by contest number:
```
contests/
  Weekly Contest/
    515/
      Q1.cpp
      Q2.cpp
      Q3.cpp
      Q4.cpp
      tests/
        Q1/
          run.cpp
        Q2/
          run.cpp
        Q3/
          run.cpp
        Q4/
          run.cpp
    516/
      ...
  Biweekly Contest/
    189/
      ...
```
Each `Qn.cpp` is split the same way as a numbered problem: it holds *only* the `Solution` class (LeetCode-submittable as-is), and its matching `tests/Qn/run.cpp` holds the `run()` call wiring it up to `runTests()`.

- **Start a new contest:**
  ```bash
  scripts/new-contest.sh
  ```
  Prompts interactively: pick `Weekly Contest` or `Biweekly Contest` from a numbered menu, enter the contest number, then enter the number of questions (blank defaults to 4), then enter the number of test cases per question (blank defaults to 3). Scaffolds `contests/<Type>/<number>/Q1..Qn.cpp` (generic TODO stubs) and matching `tests/Q1..Qn/run.cpp` harnesses -- each test directory also pre-populated with that many empty `<k>.in`/`<k>.out` placeholder pairs -- then switches `main.cpp` to `Q1`'s harness.
- **Switch to a specific contest question:**
  ```bash
  scripts/switch-contest.sh
  ```
  Interactive: pick contest type from a menu, type the contest number, then pick the question from a menu -- the type and question menus are built from what actually exists under `contests/`, so there's nothing to misspell.

`scripts/switch.sh <problem-number>` is unchanged and only handles numbered problems; contest switching is a separate script (`scripts/switch-contest.sh`) since the two live in different trees with different identifiers.

## Copying a Solution to LeetCode

Since `problems/*.cpp`/`contests/*/Qn.cpp` files contain nothing but the solution itself -- no `runner.h`, no `run()`, that all lives in the separate `run.cpp` harness -- copying one to LeetCode's submission box needs no extraction at all. `scripts/copy.sh` just finds the right file and copies it to your clipboard:

```bash
scripts/copy.sh <problem-number>   # e.g. scripts/copy.sh 3568
scripts/copy.sh                    # no arg: resolves the solution file from whatever harness main.cpp currently includes
```

Uses `pbcopy`/`xclip`/`clip.exe` depending on platform; if none are found it just prints the file instead of failing.

## Workflow
- Use `cpp-pro` for C++ implementation, debugging, and performance improvements.
- Use `leetcode-teacher` to explain patterns, invariants, and interview-ready reasoning.
- Use `leetcode-import` to turn a pasted LeetCode page into a fully-wired file in one pass — runs `scripts/new.sh`/`scripts/new-contest.sh`, writes the correct `class Solution` signature, fills `.in`/`.out` from the page's own examples, and wires `run()`'s parser. It never fills in solve logic, only structure, so it doesn't replace step 1 of the Daily Loop below — it just automates the scaffolding that used to be manual. Usage: `/leetcode-import <problem-number> <paste the LeetCode page text>`, or `/leetcode-import contest <weekly|biweekly> <contest-number> <Q1-4> <paste>` for a contest question.

All three are **required** for the Daily Loop below and are kept committed under `.claude/skills/` (what Claude Code / the `claude-acp` integration actually reads) so they're available immediately after cloning. `.agents/skills/` is Zed's *native*-agent skill format — unused by this repo's actual workflow, so it isn't tracked at all; don't recreate it unless you're switching off Claude Code. Everything else editor/agent-related is gitignored as personal, machine-specific setup, not repo content: `.zed/` (Zed debugger/task/editor config) and any *other* skill package dropped into `.claude/skills/` beyond these three — reinstall those yourself from your own global `~/.claude/skills/` if you need them.

## Daily Loop (30-60 min)
1. Pick one problem. Either run `scripts/new.sh <n> "<Title>"` and fill in the pre-created `.in`/`.out` placeholder pairs in `tests/<bucket>/<n>/` with LeetCode's examples yourself, or invoke `leetcode-import` with the pasted LeetCode page to do that scaffolding automatically. Add your own edge cases either way.
2. Solve it in `problems/<n>.cpp` without help for 15-25 minutes.
3. Ask `cpp-pro` for correctness/performance review.
4. Ask `leetcode-teacher` for pattern recap and reuse rules.

If you end up asking for the solution outright instead of solving it independently, mark the file honestly — add `// ASSISTED: <short reason>` right above `class Solution`. It's grep-able later: `grep -rl ASSISTED problems/` lists every problem that needs a solo re-attempt.

**If an AI assistant writes or provides the solution logic itself** (not just reviewing/critiquing code you wrote), it must add the `// ASSISTED: <short reason>` tag above `class Solution` in the same turn it writes the code — don't wait to be asked. This applies to `problems/*.cpp` and `contests/*/Qn.cpp` alike.

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
