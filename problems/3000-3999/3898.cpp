#include <vector>


using namespace std;

class Solution {
 public:
  vector<int> findDegrees(vector<vector<int>>& matrix) {
    int sz = matrix[0].size();
    vector<int> ans(sz, 0);

    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        ans[i] += matrix[i][j];
      }
    }

    return ans;
  }
};

