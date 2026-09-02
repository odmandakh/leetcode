#include "runner.h"
#include "problems/1000-1999/1365.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1365",
           "How Many Numbers Are Smaller Than the Current Number",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVecBracketed,  // output: [1,2,3,...]
           [](auto d) { return Solution().smallerNumbersThanCurrent(d); });
}
