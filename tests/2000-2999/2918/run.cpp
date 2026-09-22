#include "runner.h"
#include "problems/2000-2999/2918.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2918",
      "Minimum Equal Sum of Two Arrays After Replacing Zeros",
      [](istream& in) -> pair<vector<int>, vector<int>> {
        auto nums1 = Parse::intVecBracketed(in);
        auto nums2 = Parse::intVecBracketed(in);
        return {nums1, nums2};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto p) { return vector<long long>{Solution().minSum(p.first, p.second)}; });
}
