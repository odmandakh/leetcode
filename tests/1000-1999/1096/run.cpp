#include "runner.h"
#include "problems/1000-1999/1096.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1096",
      "Brace Expansion II",
      Parse::quotedString,     // input: "{a,b}{c,{d,e}}"
      Parse::strVecBracketed,  // output: ["ac","ad","ae"]
      [](auto expression) { return Solution().braceExpansionII(expression); }
  );
}
