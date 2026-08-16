#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> leftRightDifference(vector<int>& nums) {
    vector<int> answer(nums.size());

    int leftSum = 0;
    int rightSum = 0;
    for (int num : nums) {
      rightSum += num;
    }
    for (int i = 0; i < nums.size(); i++) {
      rightSum -= nums[i];
      answer[i] = abs(leftSum - rightSum);
      leftSum += nums[i];
    }

    return answer;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/2000-2999/2574", "Left and Right Sum Differences",
           Parse::intVecBracketed,                                   // TODO: pick parser
           Parse::intVecBracketed,                                   // TODO: pick parser
           [](auto d) { return Solution().leftRightDifference(d); }  // TODO: solve
  );
}
