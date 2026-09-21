#include <climits>
#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();
    // dp[i] = length of the shortest target-sum subarray fully contained in
    // arr[0..i], or INT_MAX if none exists yet.
    vector<int> dp(n, INT_MAX);

    int left = 0;
    long long sum = 0;
    int ans = INT_MAX;

    for (int right = 0; right < n; ++right) {
      sum += arr[right];
      while (sum > target) {
        sum -= arr[left];
        ++left;
      }

      if (sum == target) {
        int len = right - left + 1;
        if (left > 0 && dp[left - 1] != INT_MAX) {
          ans = min(ans, len + dp[left - 1]);
        }
        dp[right] = (right > 0) ? min(dp[right - 1], len) : len;
      } else {
        dp[right] = (right > 0) ? dp[right - 1] : INT_MAX;
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
