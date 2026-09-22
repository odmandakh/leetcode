#include "runner.h"
#include "problems/0-999/838.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/838",
      "Push Dominoes",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      Parse::strVec,        // output: single string (as a 1-element vector)
      [](auto s) { return vector<string>{Solution().pushDominoes(s)}; }
  );
}
