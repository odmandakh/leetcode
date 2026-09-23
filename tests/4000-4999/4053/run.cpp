#include "runner.h"
#include "problems/4000-4999/4053.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4053", "Minimum Operations to Make Every Element Palindromic",
      Parse::intVecBracketed,
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto nums) { return vector<long long>{Solution().minOperations(nums)}; });
}
