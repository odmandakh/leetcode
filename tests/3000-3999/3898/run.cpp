#include "runner.h"
#include "problems/3000-3999/3898.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3898", "Find the Degree of Each Vertex",
           Parse::int2DVecBracketed,  // input: [[0,1,1],[1,0,1],...]
           Parse::intVecBracketed,    // output: [2,2,2]
           [](auto d) { return Solution().findDegrees(d); });
}
