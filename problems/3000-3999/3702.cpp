#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int longestSubsequence(vector<int>& nums) {
    bool anyNonZero = false;
    int totalXor = 0;
    for (int x : nums) {
      totalXor ^= x;
      if (x != 0) anyNonZero = true;
    }
    if (!anyNonZero) return 0;
    if (totalXor != 0) return nums.size();
    return nums.size() - 1;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3702",
           "Longest Subsequence With Non-Zero Bitwise XOR",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().longestSubsequence(d)}; });
}
