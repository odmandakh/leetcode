#include "runner.h"
#include "contests/Biweekly Contest/189/Q4.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Biweekly Contest/189/tests/Q4",
      "Biweekly Contest 189 - Q4",
      Parse::intVec,                              // TODO: pick parser
      Parse::intVec,                              // TODO: pick parser
      [](auto d) { return Solution().TODO(d); }   // TODO: solve
  );
}
