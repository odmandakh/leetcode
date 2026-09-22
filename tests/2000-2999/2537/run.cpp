#include "runner.h"
#include "problems/2000-2999/2537.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2537", "Count the Number of Good Subarrays",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto p) { return vector<long long>{Solution().countGood(p.first, p.second)}; });
}
