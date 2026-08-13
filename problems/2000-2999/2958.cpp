#include <unordered_map>
#include <vector>

#include "runner.h"

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

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2958", "Length of Longest Subarray With at Most K Frequency",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().maxSubarrayLength(p.first, p.second)}; });
}
