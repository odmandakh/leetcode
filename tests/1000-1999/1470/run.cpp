#include "runner.h"
#include "problems/1000-1999/1470.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1470",
      "Shuffle the Array",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int x = 0;
        in >> x;
        return {nums, x};
      },
      Parse::intVec,  // output: space-separated ints
      [](auto p) { return Solution().shuffle(p.first, p.second); }
  );
}
