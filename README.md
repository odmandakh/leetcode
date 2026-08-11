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
This runs every `.in`/`.out` case under the active problem's `tests/<n>/` directory and prints PASS/FAIL (with timing) per case.

## Switching Problems
Only one problem is "active" (included by `main.cpp`) at a time. Each `problems/<n>.cpp` owns its own `Solution` class *and* the `run()` call that wires it up to `runTests()` — so switching never touches `CMakeLists.txt` and can't mismatch a parser to the wrong problem.

- **Switch to an already-solved problem:**
  ```bash
  scripts/switch.sh <problem-number>   # e.g. scripts/switch.sh 66
  cmake --build build && ./build/LeetCode
  ```
- **Start a brand-new problem:**
  ```bash
  scripts/new.sh <problem-number> "<Title>"   # e.g. scripts/new.sh 217 "Contains Duplicate"
  ```
  This scaffolds `problems/<n>.cpp` (with `// TODO` stubs for the `Solution` body and the parser/solve wiring) and an empty `tests/<n>/` directory, then switches `main.cpp` to point at it. Add your `.in`/`.out` test cases to `tests/<n>/`, fill in the TODOs, and build.

## Workflow
- Use `cpp-pro` for C++ implementation, debugging, and performance improvements.
- Use `leetcode-teacher` to explain patterns, invariants, and interview-ready reasoning.

## Daily Loop (30-60 min)
1. Pick one problem, run `scripts/new.sh <n> "<Title>"`, and write edge cases as `.in`/`.out` files in `tests/<n>/` first.
2. Solve it in `problems/<n>.cpp` without help for 15-25 minutes.
3. Ask `cpp-pro` for correctness/performance review.
4. Ask `leetcode-teacher` for pattern recap and reuse rules.

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
