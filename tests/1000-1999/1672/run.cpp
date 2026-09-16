#include "runner.h"
#include "problems/1000-1999/1672.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1672",
      "Richest Customer Wealth",
      Parse::int2DVecBracketed,  // input: [[1,2,3],[3,2,1]]
      Parse::intVec,             // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().maximumWealth(d)}; }
  );
}
