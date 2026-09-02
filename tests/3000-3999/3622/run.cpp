#include "runner.h"
#include "problems/3000-3999/3622.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3622", "Check Divisibility by Digit Sum and Product",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::boolVec,  // output: true/false
      [](auto n) { return vector<bool>{Solution().checkDivisibility(n)}; });
}
