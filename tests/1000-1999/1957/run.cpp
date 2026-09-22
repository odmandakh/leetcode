#include "runner.h"
#include "problems/1000-1999/1957.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1957",
      "Delete Characters to Make Fancy String",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      Parse::strVec,        // output: single string (as a 1-element vector)
      [](auto s) { return vector<string>{Solution().makeFancyString(s)}; }
  );
}
