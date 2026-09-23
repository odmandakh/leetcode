#include "runner.h"
#include "problems/4000-4999/4022.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4022", "K-th Digit in Infinite String",
      [](istream& in) -> long long {
        long long k = 0;
        in >> k;
        return k;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto k) { return vector<int>{Solution().kthDigit(k)}; });
}
