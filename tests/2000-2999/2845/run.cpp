#include <tuple>

#include "runner.h"
#include "problems/2000-2999/2845.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2845", "Count of Interesting Subarrays",
      [](istream& in) -> tuple<vector<int>, int, int> {
        auto nums = Parse::intVecBracketed(in);
        int modulo = 0, k = 0;
        in >> modulo >> k;
        return {nums, modulo, k};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto t) {
        auto& [nums, modulo, k] = t;
        return vector<long long>{Solution().countInterestingSubarrays(nums, modulo, k)};
      });
}
