#include "runner.h"
#include "problems/0-999/1.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/1",
      "Two Sum",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int x = 0;
        in >> x;
        return {nums, x};
      },
      Parse::intVec,  // output: space-separated ints
      [](auto p) { return Solution().twoSum(p.first, p.second); }
  );
}
