#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int alternatingSum(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += (i % 2 == 0 ? nums[i] : -nums[i]);
    }
    return sum;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3701", "Compute Alternating Sum",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().alternatingSum(d)}; });
}
