#include "runner.h"
#include "problems/1000-1999/1872.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1872", "Stone Game VIII",
           Parse::intVecBracketed,
           Parse::intVec,  // output: single int (as a 1-element vector)
           [](auto stones) { return vector<int>{Solution().stoneGameVIII(stones)}; });
}
