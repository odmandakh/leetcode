#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] == nums[j]) {
          count++;
        }
      }
    }
    return count;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1512", "Number of Good Pairs",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().numIdenticalPairs(d)}; });
}
