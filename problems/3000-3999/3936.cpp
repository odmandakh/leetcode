#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int minimumSwaps(vector<int>& nums) {
    int n = nums.size();
    int totalZeros = 0;
    for (int x : nums) {
      if (x == 0) totalZeros++;
    }

    int nonZeroZoneSize = n - totalZeros;
    int count = 0;
    for (int i = 0; i < nonZeroZoneSize; ++i) {
      if (nums[i] == 0) count++;
    }
    return count;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3936", "Minimum Swaps to Move Zeros to End",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().minimumSwaps(d)}; });
}
