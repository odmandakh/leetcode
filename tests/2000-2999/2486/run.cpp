#include "runner.h"
#include "problems/2000-2999/2486.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2486",
      "Append Characters to String to Make Subsequence",
      [](istream& in) -> pair<string, string> {
        string a = Parse::quotedString(in);
        string b = Parse::quotedString(in);
        return {a, b};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().appendCharacters(p.first, p.second)}; }
  );
}
