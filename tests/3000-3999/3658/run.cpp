#include "runner.h"
#include "problems/3000-3999/3658.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3658", "GCD of Odd and Even Sums",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().gcdOfOddEvenSums(n)}; });
}
