#include "runner.h"
#include "problems/1000-1999/1002.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1002",
      "Find Common Characters",
      Parse::strVecBracketed,  // input: ["bella","label","roller"]
      Parse::strVecBracketed,  // output: ["e","l","l"]
      [](auto words) { return Solution().commonChars(words); }
  );
}
