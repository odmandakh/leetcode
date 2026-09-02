#include "runner.h"
#include "problems/3000-3999/3702.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3702",
           "Longest Subsequence With Non-Zero Bitwise XOR",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().longestSubsequence(d)}; });
}
