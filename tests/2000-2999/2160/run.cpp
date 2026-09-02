#include "runner.h"
#include "problems/2000-2999/2160.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2160",
      "Minimum Sum of Four Digit Number After Splitting Digits",
      [](istream& in) -> int {
        int num = 0;
        in >> num;
        return num;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto num) { return vector<int>{Solution().minimumSum(num)}; });
}
