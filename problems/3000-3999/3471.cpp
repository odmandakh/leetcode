#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    int ans = -1, i, n = (int)nums.size();

    if (k > n) return ans;

    if (n == k) {
      sort(nums.rbegin(), nums.rend());
      return nums[0];
    }

    if (k == 1) {
      sort(nums.rbegin(), nums.rend());

      i = 0;
      while (i < n) {
        if (nums[i] == nums[i + 1]) {
          while (i + 1 < n && nums[i] == nums[i + 1]) {
            i++;
          }
        } else {
          return nums[i];
        }
        i++;
      }

      return ans;
    }

    i = 1;
    while (i < n) {
      if (nums[0] == nums[i]) break;
      i++;
    }
    if (i == n) ans = nums[0];

    i = n - 2;
    while (i >= 0) {
      if (nums[n - 1] == nums[i]) break;
      i--;
    }
    if (i == -1) ans = ans > nums[n - 1] ? ans : nums[n - 1];

    return ans;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3471", "Find the Largest Almost Missing Integer",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().largestInteger(p.first, p.second)}; });
}
