#include <vector>

#include "runner.h"

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

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3512", "Minimum Operations to Make Array Sum Divisible by K",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().minOperations(p.first, p.second)}; });
}
