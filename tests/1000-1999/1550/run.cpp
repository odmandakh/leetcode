#include "runner.h"
#include "problems/1000-1999/1550.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1550",
      "Three Consecutive Odds",
      Parse::intVecBracketed,  // input: [2,6,4,1]
      Parse::boolVec,          // output: single bool (as a 1-element vector), true/false
      [](auto arr) { return vector<bool>{Solution().threeConsecutiveOdds(arr)}; }
  );
}
