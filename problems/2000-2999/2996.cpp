#include <utility>
#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  pair<long long, int> sequential(vector<int>& nums) {
    long long sum = nums[0];
    int i = 1;

    while (i < nums.size()) {
      if (nums[i - 1] + 1 == nums[i]) {
        sum += nums[i];
      } else {
        break;
      }

      i++;
    }

    return {sum, i};
  }

  int missingInteger(vector<int>& nums) {
    auto [sum, index] = sequential(nums);
    int lowestMissing = sum;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (lowestMissing == nums[i]) {
        lowestMissing++;
      }

      if (lowestMissing < nums[i]) break;
    }

    return lowestMissing;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/2000-2999/2996",
           "Smallest Missing Integer Greater Than Sequential Prefix Sum",
           Parse::intVecBracketed,  // input: [1,2,3,...]
           Parse::intVec,           // output: single int (as a 1-element vector)
           [](auto d) { return vector<int>{Solution().missingInteger(d)}; });
}
