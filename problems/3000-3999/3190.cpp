#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int count = 0;
    for (int num : nums) {
      if (num % 3 != 0) {
        count++;
      }
    }
    return count;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3190",
           "Find Minimum Operations to Make All Elements Divisible by Three",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().minimumOperations(d)}; });
}
