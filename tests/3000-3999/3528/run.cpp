#include "runner.h"
#include "problems/3000-3999/3528.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3528",
      "Unit Conversion I",
      Parse::int2DVecBracketed,  // input: [[0,1,1],[1,0,1],...]
      Parse::intVecBracketed,    // output: [1,2,3,...]
      [](auto d) { return Solution().baseUnitConversions(d); }
  );
}
