#include <cstdlib>
#include <vector>

using namespace std;

#include <algorithm>

class Solution {
 public:
  int findSmallest(vector<int>& nums) {
    int x = nums[0];

    for (int value : nums) {
      if (value < x) x = value;
    }

    return x;
  }

  int findLargest(vector<int>& nums) {
    int x = nums[0];

    for (int value : nums) {
      if (value > x) x = value;
    }

    return x;
  }

  vector<int> findMissingElements(vector<int>& nums) {
    int s, l;
    vector<int> missing;

    s = findSmallest(nums);
    l = findLargest(nums);

    for (int i = s; i < l; ++i) {
      if (find(nums.begin(), nums.end(), i) == nums.end()) {
        missing.push_back(i);
      }
    }

    return missing;
  }
};
