#include "runner.h"
#include "problems/0-999/20.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/20",
      "Valid Parentheses",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      Parse::boolVec,       // output: single bool (as a 1-element vector), true/false
      [](auto s) { return vector<bool>{Solution().isValid(s)}; }
  );
}
