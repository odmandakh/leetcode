#include "runner.h"
#include "problems/1000-1999/1594.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1594",
      "Maximum Non Negative Product in a Matrix",
      Parse::int2DVecBracketed,  // input: [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
      Parse::intVec,             // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().maxProductPath(d)}; }
  );
}
