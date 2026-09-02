#include "runner.h"
#include "problems/3000-3999/3541.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3541", "Find Most Frequent Vowel and Consonant",
           Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
           Parse::intVec,        // output: single int (as a 1-element vector)
           [](auto s) { return vector<int>{Solution().maxFreqSum(s)}; });
}
