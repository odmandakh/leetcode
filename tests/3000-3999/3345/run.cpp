#include "runner.h"
#include "problems/3000-3999/3345.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3345",
      "Smallest Divisible Digit Product I",
      [](istream& in) -> pair<int, int> {
        int a = 0, b = 0;
        in >> a >> b;
        return {a, b};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().smallestNumber(p.first, p.second)}; }
  );
}
