#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// ASSISTED: AI replaced the O(n^2) prefix/suffix search with the O(n) sliding-window solution
// logic.
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int keep = accumulate(nums.begin(), nums.end(), 0) - x;
    if (keep < 0) return -1;

    int longest = -1;
    int sum = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
      sum += nums[right];
      while (sum > keep) sum -= nums[left++];
      if (sum == keep) longest = max(longest, right - left + 1);
    }

    return longest == -1 ? -1 : n - longest;
  }
};
