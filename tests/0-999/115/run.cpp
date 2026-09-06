#include "runner.h"
#include "problems/0-999/115.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/115",
      "Distinct Subsequences",
      [](istream& in) -> pair<string, string> {
        string a = Parse::quotedString(in);
        string b = Parse::quotedString(in);
        return {a, b};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().numDistinct(p.first, p.second)}; }
  );
}
