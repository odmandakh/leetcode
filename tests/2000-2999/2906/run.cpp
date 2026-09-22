#include "runner.h"
#include "problems/2000-2999/2906.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2906",
      "Construct Product Matrix",
      Parse::int2DVecBracketed,  // input: [[1,2],[3,4]]
      Parse::int2DVecBracketed,  // output: [[24,12],[8,6]]
      [](auto grid) { return Solution().constructProductMatrix(grid); }
  );
}
