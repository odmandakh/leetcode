#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int ans = k;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > ans) break;
      if (nums[i] == ans) ans += k;
    }

    return ans;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3718", "Smallest Missing Multiple of K",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().missingMultiple(p.first, p.second)}; });
}
