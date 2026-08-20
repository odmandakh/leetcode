#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> arr1, arr2;

    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      if (arr1.back() > arr2.back()) {
        arr1.push_back(nums[i]);
      } else {
        arr2.push_back(nums[i]);
      }
    }

    nums = arr1;
    nums.insert(nums.end(), arr2.begin(), arr2.end());

    return nums;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3069", "Distribute Elements Into Two Arrays I",
           Parse::intVecBracketed,  // input: [2,1,3]
           Parse::intVecBracketed,  // output: [2,3,1]
           [](auto d) { return Solution().resultArray(d); });
}
