#include "runner.h"
#include "problems/0-999/807.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/807",
      "Max Increase to Keep City Skyline",
      Parse::int2DVecBracketed,  // input: [[3,0,8,4],[2,4,5,7],...]
      Parse::intVec,             // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().maxIncreaseKeepingSkyline(d)}; }
  );
}
