#include "runner.h"
#include "problems/3000-3999/3418.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3418", "Maximum Amount of Money Robot Can Earn",
      Parse::int2DVecBracketed,
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto coins) { return vector<int>{Solution().maximumAmount(coins)}; });
}
