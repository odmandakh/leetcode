#include "runner.h"
#include "problems/0-999/940.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/940",
      "Distinct Subsequences II",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      Parse::intVec,        // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().distinctSubseqII(s)}; }
  );
}
