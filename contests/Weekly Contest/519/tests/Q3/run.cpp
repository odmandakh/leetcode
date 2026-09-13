#include "runner.h"
#include "contests/Weekly Contest/519/Q3.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/519/tests/Q3",
      "Weekly Contest 519 - Q3",
      Parse::intVec,                              // TODO: pick parser
      Parse::intVec,                              // TODO: pick parser
      [](auto d) { return Solution().TODO(d); }   // TODO: solve
  );
}
