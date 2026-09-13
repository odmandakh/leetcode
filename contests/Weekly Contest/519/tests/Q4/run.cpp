#include "runner.h"
#include "contests/Weekly Contest/519/Q4.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/519/tests/Q4",
      "Weekly Contest 519 - Q4",
      Parse::intVec,                              // TODO: pick parser
      Parse::intVec,                              // TODO: pick parser
      [](auto d) { return Solution().TODO(d); }   // TODO: solve
  );
}
