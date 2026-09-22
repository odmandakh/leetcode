#include "runner.h"
#include "problems/2000-2999/2302.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2302", "Count Subarrays With Score Less Than K",
      [](istream& in) -> pair<vector<int>, long long> {
        auto nums = Parse::intVecBracketed(in);
        long long k = 0;
        in >> k;
        return {nums, k};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto p) { return vector<long long>{Solution().countSubarrays(p.first, p.second)}; });
}
