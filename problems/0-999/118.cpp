#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> dp(numRows);

    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j == 0 || j == i)
          dp[i].push_back(1);
        else {
          dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
        }
      }
    }

    return dp;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/118", "Pascal's Triangle",
      [](istream& in) -> int {
        int numRows = 0;
        in >> numRows;
        return numRows;
      },
      Parse::int2DVecBracketed, [](auto numRows) { return Solution().generate(numRows); });
}
