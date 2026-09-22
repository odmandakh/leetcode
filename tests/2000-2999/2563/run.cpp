#include <tuple>

#include "runner.h"
#include "problems/2000-2999/2563.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2563", "Count the Number of Fair Pairs",
      [](istream& in) -> tuple<vector<int>, int, int> {
        auto nums = Parse::intVecBracketed(in);
        int lower = 0, upper = 0;
        in >> lower >> upper;
        return {nums, lower, upper};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto t) {
        auto& [nums, lower, upper] = t;
        return vector<long long>{Solution().countFairPairs(nums, lower, upper)};
      });
}
