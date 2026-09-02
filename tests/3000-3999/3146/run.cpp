#include "runner.h"
#include "problems/3000-3999/3146.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3146", "Permutation Difference between Two Strings",
      [](istream& in) -> pair<string, string> {
        string s = Parse::quotedString(in);
        string t = Parse::quotedString(in);
        return {s, t};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().findPermutationDifference(p.first, p.second)}; });
}
