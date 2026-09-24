#include "problems/1000-1999/1021.cpp"
#include "runner.h"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1021", "Remove Outermost Parentheses",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto s) { return vector<string>{Solution().removeOuterParentheses(s)}; });
}
