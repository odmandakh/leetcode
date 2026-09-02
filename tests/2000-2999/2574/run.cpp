#include "runner.h"
#include "problems/2000-2999/2574.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/2000-2999/2574", "Left and Right Sum Differences",
           Parse::intVecBracketed,                                   // TODO: pick parser
           Parse::intVecBracketed,                                   // TODO: pick parser
           [](auto d) { return Solution().leftRightDifference(d); }  // TODO: solve
  );
}
