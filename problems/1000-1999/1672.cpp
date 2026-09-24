#include <vector>

using namespace std;

class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    for (int i = 0; i < (int)accounts.size(); ++i) {
      int sum = 0;
      for (int j = 0; j < (int)accounts[i].size(); ++j) {
        sum += accounts[i][j];
      }

      ans = sum > ans ? sum : ans;
    }

    return ans;
  }
};
