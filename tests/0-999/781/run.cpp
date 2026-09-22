#include "runner.h"
#include "problems/0-999/781.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/781",
      "Rabbits in Forest",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVec,           // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().numRabbits(d)}; }
  );
}
