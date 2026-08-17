#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int minElement(vector<int>& nums) {
    int min = INT_MAX;
    for (int num : nums) {
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      if (sum < min) {
        min = sum;
      }
    }
    return min;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3300",
           "Minimum Element After Replacement With Digit Sum",
           Parse::intVecBracketed,  // input: [10,12,13,14]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().minElement(d)}; });
}
