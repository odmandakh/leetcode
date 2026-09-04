#include <climits>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> max(n, 0);
    vector<int> min(n, INT_MAX);

    max[0] = nums[0];
    min[n - 1] = nums[n - 1];
    for (int i = 1; i < n; ++i) {
      max[i] = max[i - 1] > nums[i] ? max[i - 1] : nums[i];
      min[n - i - 1] = min[n - i] < nums[n - i - 1] ? min[n - i] : nums[n - i - 1];
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
      if (max[i] - min[i] <= k) {
        k = max[i] - min[i];
        ans = i;
        break;
      }
    }

    return ans;
  }
};
