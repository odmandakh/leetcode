#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int ans = 0, start = 0;
    for (int i = 0; i < nums.size(); ++i) {
      freq[nums[i]]++;
      if (freq[nums[i]] > k) {
        while (start < i) {
          bool isOverflowing = (nums[start] == nums[i]);
          freq[nums[start]]--;
          start++;
          if (isOverflowing) break;
        }
      }

      if (ans < (i - start + 1)) {
        ans = i - start + 1;
      }
    }

    return ans;
  }
};

