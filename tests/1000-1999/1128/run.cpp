#include "runner.h"
#include "problems/1000-1999/1128.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1128",
      "Number of Equivalent Domino Pairs",
      Parse::int2DVecBracketed,  // input: [[1,2],[2,1],[3,4],[5,6]]
      Parse::intVec,             // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().numEquivDominoPairs(d)}; }
  );
}
