#include "runner.h"
#include "problems/2000-2999/2413.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2413", "Smallest Even Multiple",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().smallestEvenMultiple(n)}; });
}
