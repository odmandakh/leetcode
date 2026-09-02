#include "runner.h"
#include "problems/2000-2999/2091.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2091",
      "Removing Minimum and Maximum From Array",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVec,           // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().minimumDeletions(d)}; }
  );
}
