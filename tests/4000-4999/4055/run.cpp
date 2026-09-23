#include "runner.h"
#include "problems/4000-4999/4055.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4055",
      "Count Shadow Pairs II",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVec,           // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().shadowPairs(d)}; }
  );
}
