#include "runner.h"
#include "problems/0-999/746.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/0-999/746", "Min Cost Climbing Stairs",
           Parse::intVecBracketed,
           Parse::intVec,  // output: single int (as a 1-element vector)
           [](auto cost) { return vector<int>{Solution().minCostClimbingStairs(cost)}; });
}
