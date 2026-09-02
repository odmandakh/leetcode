#include <vector>


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

