#include "runner.h"
#include "problems/2000-2999/2094.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2094",
      "Finding 3-Digit Even Numbers",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVecBracketed,  // output: [1,2,3,...]
      [](auto d) { return Solution().findEvenNumbers(d); }
  );
}
