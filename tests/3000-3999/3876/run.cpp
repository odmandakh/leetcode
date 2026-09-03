#include "runner.h"
#include "problems/3000-3999/3876.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3876",
      "Construct Uniform Parity Array II",
      Parse::intVecBracketed,
      Parse::boolVec,  // output: single bool, true/false
      [](auto nums1) { return vector<bool>{Solution().uniformArray(nums1)}; });
}
