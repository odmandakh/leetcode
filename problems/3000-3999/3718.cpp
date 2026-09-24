#include <vector>


using namespace std;

class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int ans = k;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (nums[i] > ans) break;
      if (nums[i] == ans) ans += k;
    }

    return ans;
  }
};

