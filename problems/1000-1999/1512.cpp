#include <vector>


using namespace std;

class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
      for (int j = i + 1; j < (int)nums.size(); j++) {
        if (nums[i] == nums[j]) {
          count++;
        }
      }
    }
    return count;
  }
};

