#include "runner.h"
#include "problems/3000-3999/3546.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3546", "Equal Sum Grid Partition I",
      Parse::int2DVecBracketed,
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto grid) { return vector<bool>{Solution().canPartitionGrid(grid)}; });
}
