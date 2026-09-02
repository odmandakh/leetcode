#include "runner.h"
#include "problems/0-999/66.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/0-999/66", "Problem 66 · Plus One",
           Parse::intVec,                                // ← pick parser
           Parse::intVec,                                // ← pick parser
           [](auto d) { return Solution().plusOne(d); }  // ← one line solve
  );
}
