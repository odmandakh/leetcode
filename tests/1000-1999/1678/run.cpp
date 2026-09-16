#include "runner.h"
#include "problems/1000-1999/1678.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1678",
      "Goal Parser Interpretation",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
<<<<<<< Updated upstream
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto s) { return vector<string>{Solution().interpret(s)}; });
=======
      Parse::strVec,         // output: single string (as a 1-element vector)
      [](auto s) { return vector<string>{Solution().interpret(s)}; }
  );
>>>>>>> Stashed changes
}
