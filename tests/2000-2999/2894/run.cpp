#include "runner.h"
#include "problems/2000-2999/2894.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2894", "Divisible and Non-divisible Sums Difference",
      [](istream& in) -> pair<int, int> {
        int n = 0, m = 0;
        in >> n >> m;
        return {n, m};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().differenceOfSums(p.first, p.second)}; });
}
