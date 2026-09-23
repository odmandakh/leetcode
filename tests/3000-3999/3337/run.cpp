#include <tuple>

#include "runner.h"
#include "problems/3000-3999/3337.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3337",
      "Total Characters in String After Transformations II",
      [](istream& in) -> tuple<string, int, vector<int>> {
        string s = Parse::quotedString(in);
        int t = 0;
        in >> t;
        auto nums = Parse::intVecBracketed(in);
        return {s, t, nums};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto tup) {
        auto& [s, t, nums] = tup;
        return vector<int>{Solution().lengthAfterTransformations(s, t, nums)};
      });
}
