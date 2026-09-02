#include "runner.h"
#include "problems/3000-3999/3875.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3875",
      "Construct Uniform Parity Array I",
      Parse::intVecBracketed,  // input: [2,3]
      Parse::boolVec,          // output: true/false
      [](auto nums1) { return vector<bool>{Solution().uniformArray(nums1)}; });
}
