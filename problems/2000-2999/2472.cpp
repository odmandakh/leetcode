#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // ASSISTED: full solve logic implemented by Claude at user's explicit request.
  int maxPalindromes(string s, int k) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = true;
      for (int j = i + 1; j < n; ++j) {
        dp[i][j] = s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]);
      }
    }

    const int INF = n + 1;
    vector<int> firstEnd(n, INF);
    for (int i = 0; i < n; ++i) {
      for (int j = i + k - 1; j < n; ++j) {
        if (dp[i][j]) {
          firstEnd[i] = j;
          break;
        }
      }
    }

    // suffMin[i] = smallest end achievable among palindromes starting at
    // any position >= i -- picking the globally best (earliest-ending)
    // candidate available, not just the one starting exactly at i.
    vector<int> suffMin(n + 1, INF);
    for (int i = n - 1; i >= 0; --i) {
      suffMin[i] = min(firstEnd[i], suffMin[i + 1]);
    }

    int count = 0;
    int pos = 0;
    while (pos < n) {
      int e = suffMin[pos];
      if (e == INF) break;
      ++count;
      pos = e + 1;
    }

    return count;
  }
};
