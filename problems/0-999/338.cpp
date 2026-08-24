#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i >> 1] + (i & 1);
    }

    return dp;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/338", "Counting Bits",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVecBracketed, [](auto n) { return Solution().countBits(n); });
}
