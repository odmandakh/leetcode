#include "runner.h"
#include "problems/3000-3999/3392.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3392",
      "Count Subarrays of Length Three With a Condition",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVec,           // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().countSubarrays(d)}; }
  );
}
