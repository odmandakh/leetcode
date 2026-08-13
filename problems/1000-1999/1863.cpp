#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int subsetXORSum(vector<int>& nums) {
    int orAll = 0;
    for (int x : nums) orAll |= x;
    return orAll << (nums.size() - 1);
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1863", "Sum of All Subset XOR Totals",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().subsetXORSum(d)}; });
}
