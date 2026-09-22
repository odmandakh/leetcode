#include "runner.h"
#include "problems/2000-2999/2179.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2179", "Count Good Triplets in an Array",
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
      [](auto p) { return vector<long long>{Solution().goodTriplets(p.first, p.second)}; });
}
