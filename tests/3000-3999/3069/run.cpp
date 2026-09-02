#include "runner.h"
#include "problems/3000-3999/3069.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3069", "Distribute Elements Into Two Arrays I",
           Parse::intVecBracketed,  // input: [2,1,3]
           Parse::intVecBracketed,  // output: [2,3,1]
           [](auto d) { return Solution().resultArray(d); });
}
