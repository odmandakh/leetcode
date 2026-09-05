#include "runner.h"
#include "problems/3000-3999/3904.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3904",
      "Smallest Stable Index II",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int x = 0;
        in >> x;
        return {nums, x};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().firstStableIndex(p.first, p.second)}; }
  );
}
