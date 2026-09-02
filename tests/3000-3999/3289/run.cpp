#include "runner.h"
#include "problems/3000-3999/3289.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3289", "The Two Sneaky Numbers of Digitville",
           Parse::intVecBracketed,  // input: [0,1,1,0]
           Parse::intVecBracketed,  // output: [0, 1]
           [](auto d) { return Solution().getSneakyNumbers(d); });
}
