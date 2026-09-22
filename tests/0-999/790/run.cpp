#include "runner.h"
#include "problems/0-999/790.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/790",
      "Domino and Tromino Tiling",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().numTilings(n)}; }
  );
}
