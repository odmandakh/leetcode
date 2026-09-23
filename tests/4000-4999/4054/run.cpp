#include "runner.h"
#include "problems/4000-4999/4054.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4054", "Count Shadow Pairs I",
      Parse::intVecBracketed,
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto nums) { return vector<long long>{Solution().shadowPairs(nums)}; });
}
