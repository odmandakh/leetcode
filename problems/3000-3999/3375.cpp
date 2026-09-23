#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    bool seen[101] = {false};
    int cnt = 0;

    seen[k] = true;
    for (int num : nums) {
      if (num < k) return -1;

      if (!seen[num]) {
        cnt++;
        seen[num] = true;
      }
    }

    return cnt;
  }
};
