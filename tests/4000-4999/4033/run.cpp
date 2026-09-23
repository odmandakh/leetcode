#include <tuple>

#include "runner.h"
#include "problems/4000-4999/4033.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4033", "Valid K-Unique Subarrays I",
      [](istream& in) -> tuple<vector<int>, int, vector<vector<int>>> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        auto queries = Parse::int2DVecBracketed(in);
        return {nums, k, queries};
      },
      Parse::boolVecBracketed,
      [](auto t) {
        auto& [nums, k, queries] = t;
        return Solution().validSubarrays(nums, k, queries);
      });
}
