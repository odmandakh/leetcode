#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  bool divisorGame(int n) {
    vector<int> dp(n + 1, false);
    for (int i = 2; i <= n; ++i) {
      for (int x = 1; x <= i / 2; ++x) {
        if (i % x == 0 && !dp[i - x]) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1025", "Divisor Game",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector)
      [](auto n) { return vector<bool>{Solution().divisorGame(n)}; });
}
