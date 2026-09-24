#include <vector>

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
    for (int i = 0; i < (int)nums.size(); i++) {
      rightSum -= nums[i];
      answer[i] = abs(leftSum - rightSum);
      leftSum += nums[i];
    }

    return answer;
  }
};
