#include <algorithm>
#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  vector<int> maximumWeight(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<int> order(n);
    for (int i = 0; i < n; ++i) order[i] = i;
    sort(order.begin(), order.end(),
         [&](int a, int b) { return intervals[a][1] < intervals[b][1]; });

    vector<int> rSorted(n);
    for (int i = 0; i < n; ++i) rSorted[i] = intervals[order[i]][1];

    struct State {
      long long score = 0;
      vector<int> idx;
    };

    // dp[i][k] = best {score, sorted indices} using at most k intervals
    // chosen from the first i intervals in right-endpoint order.
    vector<vector<State>> dp(n + 1, vector<State>(5));

    for (int i = 1; i <= n; ++i) {
      int origIdx = order[i - 1];
      long long l = intervals[origIdx][0];
      long long w = intervals[origIdx][2];

      // j = count of intervals whose r < l (fully finished before this one starts).
      int j = lower_bound(rSorted.begin(), rSorted.end(), l) - rSorted.begin();

      dp[i][0] = dp[i - 1][0];

      for (int k = 1; k <= 4; ++k) {
        State skip = dp[i - 1][k];

        State take;
        take.score = dp[j][k - 1].score + w;
        take.idx = dp[j][k - 1].idx;
        take.idx.insert(upper_bound(take.idx.begin(), take.idx.end(), origIdx), origIdx);

        // Prefer higher score; on a tie, prefer the lexicographically smaller
        // index array (shorter-and-a-prefix counts as smaller, matching
        // std::vector's operator<).
        if (take.score > skip.score ||
            (take.score == skip.score && take.idx < skip.idx)) {
          dp[i][k] = std::move(take);
        } else {
          dp[i][k] = std::move(skip);
        }
      }
    }

    return dp[n][4].idx;
  }
};
