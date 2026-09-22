#include "runner.h"
#include "problems/0-999/861.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/861",
      "Score After Flipping Matrix",
      Parse::int2DVecBracketed,  // input: [[0,0,1,1],[1,0,1,0],...]
      Parse::intVec,             // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().matrixScore(d)}; }
  );
}
