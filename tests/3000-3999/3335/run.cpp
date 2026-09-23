#include "runner.h"
#include "problems/3000-3999/3335.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3335",
      "Total Characters in String After Transformations I",
      [](istream& in) -> pair<string, int> {
        string s = Parse::quotedString(in);
        int t = 0;
        in >> t;
        return {s, t};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().lengthAfterTransformations(p.first, p.second)}; });
}
