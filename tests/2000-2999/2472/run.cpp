#include "runner.h"
#include "problems/2000-2999/2472.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2472",
      "Maximum Number of Non-overlapping Palindrome Substrings",
      [](istream& in) -> pair<string, int> {
        string s = Parse::quotedString(in);
        int k = 0;
        in >> k;
        return {s, k};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) {
        return vector<int>{Solution().maxPalindromes(p.first, p.second)};
      });
}
