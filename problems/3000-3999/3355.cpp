#include <vector>

using namespace std;

class Solution {
 public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> line(nums.size() + 1);

    for (const auto& query : queries) {
      line[query[0]]++;
      line[query[1] + 1]--;
    }

    int decremant = 0;
    for (int i = 0; i < nums.size(); ++i) {
      decremant += line[i];
      if (decremant < nums[i]) return false;
    }

    return true;
  }
};
