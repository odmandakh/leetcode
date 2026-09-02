#include "runner.h"
#include "problems/1000-1999/1929.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1929", "Concatenation of Array",
           Parse::intVecBracketed,                                // TODO: pick parser
           Parse::intVecBracketed,                                // TODO: pick parser
           [](auto d) { return Solution().getConcatenation(d); }  // TODO: solve
  );
}
