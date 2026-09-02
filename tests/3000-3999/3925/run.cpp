#include "runner.h"
#include "problems/3000-3999/3925.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3925", "Concatenate Array With Reverse",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVecBracketed,  // output: [1,2,3,...]
           [](auto d) { return Solution().concatWithReverse(d); });
}
