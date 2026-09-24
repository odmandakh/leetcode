#include <vector>

using namespace std;

class Solution {
 public:
  int smallestIndex(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int tmp = nums[i];
      int sumOfDig = 0;
      while (tmp) {
        sumOfDig += tmp % 10;
        tmp /= 10;
      }

      if (i == sumOfDig) return i;
    }

    return -1;
  }
};
