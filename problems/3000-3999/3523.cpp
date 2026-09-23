#include <vector>

using namespace std;

class Solution {
 public:
  int maximumPossibleSize(vector<int>& nums) {
    int count = 1;
    int n = nums.size();
    int last = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] >= last) {
        count++;
        last = nums[i];
      } else {
        last = max(last, nums[i]);
      }
    }

    return count;
  }
};
