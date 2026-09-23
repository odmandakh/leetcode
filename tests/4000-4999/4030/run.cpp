#include "runner.h"
#include "problems/4000-4999/4030.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4030", "Check ASCII Palindromic",
      Parse::quotedString,
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto s) { return vector<bool>{Solution().isPalindromic(s)}; });
}
