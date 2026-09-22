#include <vector>

using namespace std;

class Solution {
 public:
  int matrixScore(vector<vector<int>>& grid) {
    int i, j, row_size, col_size, coef, cnt;
    long long int ans;
    vector<long long int> rows(grid.size(), 0);

    i = 0;
    col_size = grid.size();
    row_size = grid[0].size();
    while (i < col_size) {
      j = 0;
      while (j < row_size) {
        rows[i] = rows[i] << 1;
        if (grid[i][j] == 1) {
          rows[i] += 1;
        }
        j++;
      }
      i++;
    }

    i = 0;
    ans = 0;
    while (i < col_size) {
      if (grid[i][0] == 0) {
        rows[i] = ((1 << row_size) - 1) - rows[i];
        j = 0;
        while (j < row_size) {
          grid[i][j] = 1 - grid[i][j];
          j++;
        }
      }
      ans += rows[i];
      i++;
    }

    coef = 1;
    j = row_size - 1;
    while (j > 0) {
      i = 0;
      cnt = 0;
      while (i < col_size) {
        cnt += grid[i][j];

        i++;
      }

      if (cnt <= (col_size / 2)) {
        ans += (col_size - 2 * cnt) * coef;
      }

      coef = coef << 1;
      j--;
    }

    return ans;
  }
};
