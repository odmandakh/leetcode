#include "runner.h"
#include "contests/Weekly Contest/516/Q1.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/contests/Weekly Contest/516/tests/Q1",
           "Weekly Contest 516 - Q1",
           Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
           Parse::boolVec,       // output: true/false
           [](auto s) { return vector<bool>{Solution().isPalindromic(s)}; });
}
