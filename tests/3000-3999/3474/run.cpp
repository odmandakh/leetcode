#include "runner.h"
#include "problems/3000-3999/3474.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3474", "Lexicographically Smallest Generated String",
      [](istream& in) -> pair<string, string> {
        string str1 = Parse::quotedString(in);
        string str2 = Parse::quotedString(in);
        return {str1, str2};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto p) { return vector<string>{Solution().generateString(p.first, p.second)}; });
}
