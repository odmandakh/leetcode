#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size();
    int m = moveTime[0].size();

    // Define directions: right, down, left, up
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Priority queue to store {time, row, col}
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({0, 0, 0});  // Start at (0,0) with time 0

    // Track minimum time to reach each cell
    vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
    minTime[0][0] = 0;

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      int time = curr[0];
      int r = curr[1];
      int c = curr[2];

      // If we reached the destination
      if (r == n - 1 && c == m - 1) return time;

      // Skip if we already found a better time for this cell
      if (time > minTime[r][c]) continue;

      // Try all four directions
      for (auto& dir : dirs) {
        int nr = r + dir.first;
        int nc = c + dir.second;

        // Check if the new position is valid
        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
          // Calculate time to move to the next cell
          int nextTime = max(time + 1, moveTime[nr][nc] + 1);

          if (nextTime < minTime[nr][nc]) {
            minTime[nr][nc] = nextTime;
            pq.push({nextTime, nr, nc});
          }
        }
      }
    }

    return -1;  // Should never reach here if grid is valid
  }
};
