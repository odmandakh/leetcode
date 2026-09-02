#include "runner.h"
#include "problems/1000-1999/1512.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1512", "Number of Good Pairs",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().numIdenticalPairs(d)}; });
}
