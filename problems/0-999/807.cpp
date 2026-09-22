#include <vector>

using namespace std;

class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size();
    int rowMax[50] = {0}, colMax[50] = {0}, row, col, ans = 0;

    row = 0;
    while (row < n) {
      col = 0;
      while (col < n) {
        if (rowMax[row] < grid[row][col]) {
          rowMax[row] = grid[row][col];
        }
        if (colMax[col] < grid[row][col]) {
          colMax[col] = grid[row][col];
        }

        col++;
      }

      row++;
    }

    row = 0;
    while (row < n) {
      col = 0;
      while (col < n) {
        if (rowMax[row] > colMax[col]) {
          ans += (colMax[col] - grid[row][col]);
        } else {
          ans += (rowMax[row] - grid[row][col]);
        }

        col++;
      }

      row++;
    }

    return ans;
  }
};
