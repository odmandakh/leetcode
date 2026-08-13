#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> concatWithReverse(vector<int>& nums) {
    vector<int> ans = nums;
    reverse(nums.begin(), nums.end());
    ans.insert(ans.end(), nums.begin(), nums.end());
    return ans;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3925", "Concatenate Array With Reverse",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVecBracketed,  // output: [1,2,3,...]
           [](auto d) { return Solution().concatWithReverse(d); });
}
