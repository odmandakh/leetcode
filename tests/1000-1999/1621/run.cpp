#include "runner.h"
#include "problems/1000-1999/1621.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1621",
      "Number of Sets of K Non-Overlapping Line Segments",
      [](istream& in) -> pair<int, int> {
        int a = 0, b = 0;
        in >> a >> b;
        return {a, b};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().numberOfSets(p.first, p.second)}; }
  );
}
