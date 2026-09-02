#include <vector>


using namespace std;

class Solution {
 public:
  int subsetXORSum(vector<int>& nums) {
    int orAll = 0;
    for (int x : nums) orAll |= x;
    return orAll << (nums.size() - 1);
  }
};

