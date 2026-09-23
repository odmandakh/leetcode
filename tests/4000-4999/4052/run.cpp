#include <tuple>

#include "runner.h"
#include "problems/4000-4999/4052.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4052", "Cyclically Shift Rows and Columns",
      [](istream& in) -> tuple<int, vector<vector<int>>, vector<int>, vector<int>> {
        int n = 0;
        in >> n;
        auto grid = Parse::int2DVecBracketed(in);
        auto rowShift = Parse::intVecBracketed(in);
        auto colShift = Parse::intVecBracketed(in);
        return {n, grid, rowShift, colShift};
      },
      Parse::int2DVecBracketed,
      [](auto t) {
        auto& [n, grid, rowShift, colShift] = t;
        return Solution().cyclicShift(n, grid, rowShift, colShift);
      });
}
