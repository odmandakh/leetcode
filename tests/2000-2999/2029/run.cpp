#include "runner.h"
#include "problems/2000-2999/2029.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/2000-2999/2029", "Stone Game IX", Parse::intVecBracketed,
           Parse::boolVec,  // output: true/false
           [](auto d) { return vector<bool>{Solution().stoneGameIX(d)}; });
}
