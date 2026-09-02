#include "runner.h"
#include "problems/0-999/338.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/338", "Counting Bits",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVecBracketed, [](auto n) { return Solution().countBits(n); });
}
