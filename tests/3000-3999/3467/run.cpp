#include "runner.h"
#include "problems/3000-3999/3467.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3467", "Transform Array by Parity",
           Parse::intVecBracketed,                              // TODO: pick parser
           Parse::intVecBracketed,                              // TODO: pick parser
           [](auto d) { return Solution().transformArray(d); }  // TODO: solve
  );
}
