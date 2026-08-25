#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> ans(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] < nums[j]) ans[j]++;
        if (nums[i] > nums[j]) ans[i]++;
      }
    }

    return ans;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1365",
           "How Many Numbers Are Smaller Than the Current Number",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVecBracketed,  // output: [1,2,3,...]
           [](auto d) { return Solution().smallerNumbersThanCurrent(d); });
}
