#include "runner.h"
#include "problems/3000-3999/3341.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3341", "Find Minimum Time to Reach Last Room I",
      Parse::int2DVecBracketed,
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto moveTime) { return vector<int>{Solution().minTimeToReach(moveTime)}; });
}
