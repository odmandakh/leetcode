#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long count = 0;
    int n = nums.size();

    for (int j = 0; j < n; ++j) {
      int left = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]) - nums.begin();
      int right = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]) - nums.begin();
      count += (right - left);
    }

    return count;
  }
};
