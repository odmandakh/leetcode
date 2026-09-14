#include "runner.h"
#include "problems/0-999/836.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/836",
      "Rectangle Overlap",
      [](istream& in) -> pair<vector<int>, vector<int>> {
        auto rec1 = Parse::intVecBracketed(in);
        auto rec2 = Parse::intVecBracketed(in);
        return {rec1, rec2};
      },
      Parse::boolVec,  // output: single bool, true/false
      [](auto p) {
        return vector<bool>{Solution().isRectangleOverlap(p.first, p.second)};
      });
}
