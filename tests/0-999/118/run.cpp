#include "runner.h"
#include "problems/0-999/118.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/118", "Pascal's Triangle",
      [](istream& in) -> int {
        int numRows = 0;
        in >> numRows;
        return numRows;
      },
      Parse::int2DVecBracketed, [](auto numRows) { return Solution().generate(numRows); });
}
