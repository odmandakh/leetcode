#include "runner.h"
#include "contests/Weekly Contest/516/Q4.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/516/tests/Q4", "Weekly Contest 516 - Q4",
      [](istream& in) -> tuple<vector<int>, int, vector<vector<int>>> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        auto queries = Parse::int2DVecBracketed(in);
        return {nums, k, queries};
      },
      Parse::boolVecBracketed,  // output: [true,false,...]
      [](auto t) {
        auto [nums, k, queries] = t;
        return Solution().validSubarrays(nums, k, queries);
      });
}
