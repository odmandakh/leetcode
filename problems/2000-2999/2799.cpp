#include <vector>

using namespace std;

class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    int totalUnique = 0;
    bool uniq[2001] = {false};

    // Count total number of distinct elements in the array
    for (int num : nums) {
      if (!uniq[num]) {
        uniq[num] = true;
        totalUnique++;
      }
    }

    int ans = 0;
    int left = 0;
    int sub[2001] = {0};
    int windowUnique = 0;

    for (int right = 0; right < (int)nums.size(); ++right) {
      // Add nums[right] to the window
      if (sub[nums[right]] == 0) windowUnique++;
      sub[nums[right]]++;

      // Shrink from the left while window is complete
      while (windowUnique == totalUnique) {
        ans += nums.size() - right;
        sub[nums[left]]--;
        if (sub[nums[left]] == 0) windowUnique--;
        left++;
      }
    }

    return ans;
  }
};
