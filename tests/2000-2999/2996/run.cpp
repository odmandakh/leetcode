#include "runner.h"
#include "problems/2000-2999/2996.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/2000-2999/2996",
           "Smallest Missing Integer Greater Than Sequential Prefix Sum",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().missingInteger(d)}; });
}
