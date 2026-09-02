#include "runner.h"
#include "contests/Biweekly Contest/189/Q3.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Biweekly Contest/189/tests/Q3", "Biweekly Contest 189 - Q3",
      [](istream& in) -> long long {
        long long k = 0;
        in >> k;
        return k;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto k) { return vector<int>{Solution().kthDigit(k)}; });
}
