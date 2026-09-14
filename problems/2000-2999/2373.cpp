#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> ans(n - 2, vector<int>(n - 2));

    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        int max = 0;
        for (int x = i - 1; x <= i + 1; ++x) {
          for (int y = j - 1; y <= j + 1; ++y) {
            max = grid[x][y] > max ? grid[x][y] : max;
          }
        }

        ans[i - 1][j - 1] = max;
      }
    }

    return ans;
  }
};
