#include "runner.h"
#include "problems/0-999/13.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/13",
      "Roman to Integer",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      Parse::intVec,        // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().romanToInt(s)}; }
  );
}
