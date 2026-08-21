#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    for (int i = 0; i < k; ++i) {
      int minIndex = 0;
      for (int j = 1; j < nums.size(); ++j) {
        if (nums[j] < nums[minIndex]) {
          minIndex = j;
        }
      }
      nums[minIndex] *= multiplier;
    }
    return nums;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3264",
      "Final Array State After K Multiplication Operations I",
      [](istream& in) -> tuple<vector<int>, int, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0, multiplier = 0;
        in >> k >> multiplier;
        return {nums, k, multiplier};
      },
      Parse::intVecBracketed,
      [](auto t) { return Solution().getFinalState(get<0>(t), get<1>(t), get<2>(t)); });
}
