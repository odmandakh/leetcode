#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: AI fixed the final-return bug (top of the staircase is reachable
// free from either of the last two steps, not just the last one).
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n);

    if (n < 2) return 0;

    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; ++i) {
      if (dp[i - 1] > dp[i - 2])
        dp[i] = dp[i - 2] + cost[i];
      else
        dp[i] = dp[i - 1] + cost[i];
    }

    return min(dp[n - 1], dp[n - 2]);
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/0-999/746", "Min Cost Climbing Stairs",
           Parse::intVecBracketed,
           Parse::intVec,  // output: single int (as a 1-element vector)
           [](auto cost) { return vector<int>{Solution().minCostClimbingStairs(cost)}; });
}
