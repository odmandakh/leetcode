#include <string>
#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int numDistinct(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (a[i - 1] == b[j - 1]) dp[i][j] += dp[i - 1][j - 1];
      }
    }

    return static_cast<int>(dp[n][m]);
  }
};
