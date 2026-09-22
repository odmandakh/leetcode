#include "runner.h"
#include "problems/1000-1999/1920.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1920",
      "Build Array from Permutation",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVecBracketed,  // output: [1,2,3,...]
      [](auto d) { return Solution().buildArray(d); }
  );
}
