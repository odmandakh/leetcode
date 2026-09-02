#include "runner.h"
#include "problems/3000-3999/3734.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3734", "Lexicographically Smallest Palindromic Permutation Greater Than Target",
      [](istream& in) -> pair<string, string> {
        string s = Parse::quotedString(in);
        string target = Parse::quotedString(in);
        return {s, target};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedString(in)}; },
      [](auto p) { return vector<string>{Solution().lexPalindromicPermutation(p.first, p.second)}; });
}
