#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());

    int index = 0;
    while (index < (int)nums.size()) {
      if (nums[index] >= lower) break;
      index++;
    }

    vector<vector<int>> ans;
    int i = lower;

    if (index == (int)nums.size()) {
      if (i <= upper) ans.push_back({i, upper});
      return ans;
    }

    while (i <= upper) {
      int start = i;
      while (i < nums[index] && i <= upper) i++;

      if (i > start) ans.push_back({start, i - 1});

      i++;
      while (index < (int)nums.size() && nums[index] < i) index++;
      if (index == (int)nums.size()) break;
    }

    if (i <= upper) ans.push_back({i, upper});

    return ans;
  }
};
