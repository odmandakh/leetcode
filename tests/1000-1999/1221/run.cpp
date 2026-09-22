#include "runner.h"
#include "problems/1000-1999/1221.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1221",
      "Split a String in Balanced Strings",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      Parse::intVec,        // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().balancedStringSplit(s)}; }
  );
}
