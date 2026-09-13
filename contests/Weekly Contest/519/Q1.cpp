#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift,
                                  vector<int>& colShift) {
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      int k = rowShift[i];
      for (int p = 0; p < n; ++p) {
        temp[i][p] = grid[i][(p + k) % n];
      }
    }

    vector<vector<int>> result(n, vector<int>(n));
    for (int j = 0; j < n; ++j) {
      int k = colShift[j];
      for (int p = 0; p < n; ++p) {
        result[p][j] = temp[(p + k) % n][j];
      }
    }

    return result;
  }
};
