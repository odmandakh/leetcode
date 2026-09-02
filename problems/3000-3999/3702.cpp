#include <vector>


using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int longestSubsequence(vector<int>& nums) {
    bool anyNonZero = false;
    int totalXor = 0;
    for (int x : nums) {
      totalXor ^= x;
      if (x != 0) anyNonZero = true;
    }
    if (!anyNonZero) return 0;
    if (totalXor != 0) return nums.size();
    return nums.size() - 1;
  }
};

