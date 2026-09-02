#include <vector>


using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
      sum %= k;
    }

    return sum;
  }
};

