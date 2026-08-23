#include <algorithm>
#include <unordered_map>
#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: fixed factorization edge cases and wired the sliding-window
class Solution {
 public:
  int longestSubarray(vector<int>& nums, int k) {
    vector<vector<int>> distP;
    for (int num : nums) {
      vector<int> dist;
      for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
          dist.push_back(i);
          while (num % i == 0) num /= i;
        }
      }
      if (num > 1) dist.push_back(num);
      distP.push_back(dist);
    }

    int left = 0;
    int distinctCount = 0;
    unordered_map<int, int> freq;
    int ans = 0;
    for (int right = 0; right < nums.size(); ++right) {
      for (int prime : distP[right]) {
        if (freq[prime]++ == 0) distinctCount++;
      }

      while (distinctCount > k) {
        for (int prime : distP[left]) {
          if (--freq[prime] == 0) distinctCount--;
        }
        left++;
      }

      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/516/tests/Q3", "Weekly Contest 516 - Q3",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().longestSubarray(p.first, p.second)}; });
}
