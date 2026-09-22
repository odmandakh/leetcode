#include <tuple>

#include "runner.h"
#include "problems/2000-2999/2444.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2444", "Count Subarrays With Fixed Bounds",
      [](istream& in) -> tuple<vector<int>, int, int> {
        auto nums = Parse::intVecBracketed(in);
        int minK = 0, maxK = 0;
        in >> minK >> maxK;
        return {nums, minK, maxK};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto t) {
        auto& [nums, minK, maxK] = t;
        return vector<long long>{Solution().countSubarrays(nums, minK, maxK)};
      });
}
