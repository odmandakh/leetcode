#include "runner.h"
#include "problems/3000-3999/3161.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3161", "Problem 3161 · Block Placement Queries",
           Parse::int2DVec,                                 // input parser
           Parse::boolVec,                                  // output parser
           [](auto q) { return Solution().getResults(q); }  // solve
  );
}
