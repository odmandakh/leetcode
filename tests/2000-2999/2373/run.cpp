#include "runner.h"
#include "problems/2000-2999/2373.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2373",
      "Largest Local Values in a Matrix",
      Parse::int2DVecBracketed,  // input: [[9,9,8,1],[5,6,2,6],...]
      Parse::int2DVecBracketed,  // output: [[9,9],[8,6]]
      [](auto grid) { return Solution().largestLocal(grid); });
}
