#include "runner.h"
#include "problems/3000-3999/3116.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3116",
      "Kth Smallest Amount With Single Denomination Combination",
      [](istream& in) -> pair<vector<int>, int> {
        auto coins = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {coins, k};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto p) { return vector<long long>{Solution().findKthSmallest(p.first, p.second)}; });
}
