#include "runner.h"
#include <algorithm>
#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[minIdx]) minIdx = i;
      if (nums[i] > nums[maxIdx]) maxIdx = i;
    }

    int lo = min(minIdx, maxIdx), hi = max(minIdx, maxIdx);
    int fromFront = hi + 1;              // remove everything up through the later one
    int fromBack = n - lo;               // remove everything from the earlier one onward
    int fromBoth = (lo + 1) + (n - hi);  // earlier one from the front, later one from the back
    return min({fromFront, fromBack, fromBoth});
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2091",
      "Removing Minimum and Maximum From Array",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVec,           // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().minimumDeletions(d)}; }
  );
}
