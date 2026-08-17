#include <vector>

#include "runner.h"

using namespace std;

class Solution {
  vector<vector<int>> memo;
  vector<int> prefix;

  int rangeSum(int i, int j) { return prefix[j + 1] - prefix[i]; }

  int solve(int i, int j) {
    if (i == j) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    int best = 0;
    int candidate = 0;
    for (int k = i; k < j; ++k) {
      long long leftSum = rangeSum(i, k);
      long long rightSum = rangeSum(k + 1, j);

      if (leftSum > rightSum) {
        candidate = rightSum + solve(k + 1, j);
      } else if (leftSum < rightSum) {
        candidate = leftSum + solve(i, k);
      } else {
        candidate = leftSum + max(solve(i, k), solve(k + 1, j));
      }

      best = max(best, candidate);
    }

    memo[i][j] = best;
    return best;
  }

 public:
  int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();
    prefix.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stoneValue[i];
    memo.assign(n, vector<int>(n, -1));
    return solve(0, n - 1);
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1563", "Stone Game V",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().stoneGameV(d)}; });
}
