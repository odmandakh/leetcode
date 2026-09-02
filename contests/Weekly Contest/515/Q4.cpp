#include <climits>
#include <tuple>
#include <vector>


using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
    int m = requests.size();
    auto diff = [](long long a, long long b) { return a > b ? a - b : b - a; };

    vector<vector<long long>> dp(1 << m, vector<long long>(m, LLONG_MAX));
    for (int i = 0; i < m; ++i) {
      dp[1 << i][i] = max<long long>(diff(requests[i][1], start), requests[i][0]);
    }

    for (int mask = 1; mask < (1 << m); ++mask) {
      for (int last = 0; last < m; ++last) {
        if (!(mask & (1 << last)) || dp[mask][last] == LLONG_MAX) continue;
        long long t = dp[mask][last];
        for (int j = 0; j < m; ++j) {
          if (mask & (1 << j)) continue;
          long long arriveTime = t + diff(requests[last][1], requests[j][1]);
          long long fulfillTime = max<long long>(arriveTime, requests[j][0]);
          int newMask = mask | (1 << j);
          dp[newMask][j] = min(dp[newMask][j], fulfillTime);
        }
      }
    }

    int full = (1 << m) - 1;
    long long ans = LLONG_MAX;
    for (int i = 0; i < m; ++i) ans = min(ans, dp[full][i]);
    return ans;
  }
};

