#include "runner.h"
#include <tuple>

#include "problems/3000-3999/3525.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3525",
      "Find X Value of Array II",
      [](istream& in) -> tuple<vector<int>, int, vector<vector<int>>> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        auto queries = Parse::int2DVecBracketed(in);
        return {nums, k, queries};
      },
      Parse::intVecBracketed,  // output: [2,2,2]
      [](auto t) {
        auto [nums, k, queries] = t;
        return Solution().resultArray(nums, k, queries);
      }
  );
}
