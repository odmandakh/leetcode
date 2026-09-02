#include "runner.h"
#include "problems/3000-3999/3300.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3300",
           "Minimum Element After Replacement With Digit Sum",
           Parse::intVecBracketed,  // input: [10,12,13,14]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().minElement(d)}; });
}
