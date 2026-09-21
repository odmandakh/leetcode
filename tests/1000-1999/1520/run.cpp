#include "runner.h"
#include "problems/1000-1999/1520.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1520",
      "Maximum Number of Non-Overlapping Substrings",
      Parse::quotedString,      // input: "abc" or 'abc' (quotes stripped)
      Parse::strVecBracketed,   // output: ["e","f","ccc"]
      [](auto s) { return Solution().maxNumOfSubstrings(s); }
  );
}
