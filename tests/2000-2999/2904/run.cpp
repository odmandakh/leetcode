#include "runner.h"
#include "problems/2000-2999/2904.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2904",
      "Shortest and Lexicographically Smallest Beautiful String",
      [](istream& in) -> pair<string, int> {
        string s = Parse::quotedString(in);
        int k = 0;
        in >> k;
        return {s, k};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedString(in)}; },
      [](auto p) {
        return vector<string>{Solution().shortestBeautifulSubstring(p.first, p.second)};
      });
}
