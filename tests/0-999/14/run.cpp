#include "runner.h"
#include "problems/0-999/14.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/14",
      "Longest Common Prefix",
      Parse::strVecBracketed,  // input: ["flower","flow","flight"]
      [](istream& in) -> vector<string> {
        // Whole-line read (not Parse::strVec's whitespace-tokenized `>>`) so
        // an empty-string answer (e.g. "no common prefix") round-trips
        // correctly instead of silently parsing as a 0-element vector.
        string line;
        getline(in, line);
        return {line};
      },
      [](auto strs) { return vector<string>{Solution().longestCommonPrefix(strs)}; }
  );
}
