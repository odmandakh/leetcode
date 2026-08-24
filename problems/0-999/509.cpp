#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/509", "Fibonacci Number",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().fib(n)}; });
}
