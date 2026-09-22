#include "runner.h"
#include "problems/1000-1999/1922.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1922",
      "Count Good Numbers",
      [](istream& in) -> long long {
        long long n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().countGoodNumbers(n)}; }
  );
}
