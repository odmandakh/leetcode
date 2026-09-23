#include "runner.h"
#include "problems/4000-4999/4021.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4021",
      "Minimum Operations to Make a Rotated Palindrome I",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      Parse::intVec,        // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().minOperations(s)}; }
  );
}
