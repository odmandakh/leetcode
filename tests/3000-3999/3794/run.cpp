#include "runner.h"
#include "problems/3000-3999/3794.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3794",
      "Reverse String Prefix",
      [](istream& in) -> pair<string, int> {
        string s = Parse::quotedString(in);
        int k = 0;
        in >> k;
        return {s, k};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto p) {
        return vector<string>{Solution().reversePrefix(p.first, p.second)};
      });
}
