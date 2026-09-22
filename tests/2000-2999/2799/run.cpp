#include "runner.h"
#include "problems/2000-2999/2799.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2799",
      "Count Complete Subarrays in an Array",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVec,           // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().countCompleteSubarrays(d)}; }
  );
}
