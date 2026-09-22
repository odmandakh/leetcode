#include "runner.h"
#include "problems/1000-1999/1007.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1007",
      "Minimum Domino Rotations For Equal Row",
      [](istream& in) -> pair<vector<int>, vector<int>> {
        auto tops = Parse::intVecBracketed(in);
        auto bottoms = Parse::intVecBracketed(in);
        return {tops, bottoms};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().minDominoRotations(p.first, p.second)}; }
  );
}
