#include "runner.h"
#include "problems/3000-3999/3689.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3689",
      "Maximum Total Value",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      [](istream& in) -> vector<long long> {
        long long x = 0;
        in >> x;
        return {x};
      },
      [](auto p) {
        return vector<long long>{Solution().maxTotalValue(p.first, p.second)};
      });
}
