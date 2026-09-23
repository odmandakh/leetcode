#include "runner.h"
#include "problems/3000-3999/3731.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3731",
      "Find Missing Elements",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVecBracketed,  // output: [1,2,3,...]
      [](auto d) { return Solution().findMissingElements(d); }
  );
}
