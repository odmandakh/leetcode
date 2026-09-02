#include <vector>


using namespace std;

class Solution {
 public:
  int minimumSwaps(vector<int>& nums) {
    int n = nums.size();
    int totalZeros = 0;
    for (int x : nums) {
      if (x == 0) totalZeros++;
    }

    int nonZeroZoneSize = n - totalZeros;
    int count = 0;
    for (int i = 0; i < nonZeroZoneSize; ++i) {
      if (nums[i] == 0) count++;
    }
    return count;
  }
};

