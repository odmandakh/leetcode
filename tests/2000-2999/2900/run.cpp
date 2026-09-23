#include "runner.h"
#include "problems/2000-2999/2900.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2900",
      "Longest Unequal Adjacent Groups Subsequence I",
      [](istream& in) -> pair<vector<string>, vector<int>> {
        auto words = Parse::strVecBracketed(in);
        auto groups = Parse::intVecBracketed(in);
        return {words, groups};
      },
      Parse::strVecBracketed,
      [](auto p) { return Solution().getLongestSubsequence(p.first, p.second); });
}
