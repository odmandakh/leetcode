#include <tuple>

#include "runner.h"
#include "problems/3000-3999/3643.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3643", "Flip Square Submatrix Vertically",
      [](istream& in) -> tuple<vector<vector<int>>, int, int, int> {
        auto grid = Parse::int2DVecBracketed(in);
        int x = 0, y = 0, k = 0;
        in >> x >> y >> k;
        return {grid, x, y, k};
      },
      Parse::int2DVecBracketed,
      [](auto t) {
        auto& [grid, x, y, k] = t;
        return Solution().reverseSubmatrix(grid, x, y, k);
      });
}
