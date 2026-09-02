#include "runner.h"
#include "problems/3000-3999/3720.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3720",
      "Lexicographically Smallest Permutation Greater Than Target",
      [](istream& in) -> pair<string, string> {
        string s = Parse::quotedString(in);
        string target = Parse::quotedString(in);
        return {s, target};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedString(in)}; },
      [](auto p) { return vector<string>{Solution().lexGreaterPermutation(p.first, p.second)}; });
}
