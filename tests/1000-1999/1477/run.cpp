#include "runner.h"
#include "problems/1000-1999/1477.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1477",
      "Find Two Non-overlapping Sub-arrays Each With Target Sum",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int x = 0;
        in >> x;
        return {nums, x};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().minSumOfLengths(p.first, p.second)}; }
  );
}
