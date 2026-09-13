#include "runner.h"
#include "problems/0-999/835.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/835",
      "Image Overlap",
      [](istream& in) -> pair<vector<vector<int>>, vector<vector<int>>> {
        auto img1 = Parse::int2DVecBracketed(in);
        auto img2 = Parse::int2DVecBracketed(in);
        return {img1, img2};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().largestOverlap(p.first, p.second)}; }
  );
}
