#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: AI provided the suffix-DP / telescoping-prefix-sum solution logic directly.
class Solution {
 public:
  int stoneGameVIII(vector<int>& stones) {
    int n = stones.size();
    vector<long long> pre(n);
    pre[0] = stones[0];
    for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + stones[i];

    long long dp = pre[n - 1];
    for (int i = n - 2; i >= 1; --i) {
      dp = max(dp, pre[i] - dp);
    }
    return (int)dp;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1872", "Stone Game VIII",
           Parse::intVecBracketed,
           Parse::intVec,  // output: single int (as a 1-element vector)
           [](auto stones) { return vector<int>{Solution().stoneGameVIII(stones)}; });
}
