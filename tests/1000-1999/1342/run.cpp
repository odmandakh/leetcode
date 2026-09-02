#include "runner.h"
#include "problems/1000-1999/1342.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1342", "Number of Steps to Reduce a Number to Zero",
      [](istream& in) -> int {
        int num = 0;
        in >> num;
        return num;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto num) { return vector<int>{Solution().numberOfSteps(num)}; });
}
