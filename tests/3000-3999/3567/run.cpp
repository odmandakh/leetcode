#include "runner.h"
#include "problems/3000-3999/3567.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3567", "Minimum Absolute Difference in Sliding Submatrix",
      [](istream& in) -> pair<vector<vector<int>>, int> {
        auto grid = Parse::int2DVecBracketed(in);
        int k = 0;
        in >> k;
        return {grid, k};
      },
      Parse::int2DVecBracketed,
      [](auto p) { return Solution().minAbsDiff(p.first, p.second); });
}
