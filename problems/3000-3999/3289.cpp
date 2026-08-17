#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    vector<int> freq(nums.size() - 2, 0);
    vector<int> result;
    for (int num : nums) {
      freq[num]++;
      if (freq[num] == 2) {
        result.push_back(num);
      }
    }
    return result;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3289", "The Two Sneaky Numbers of Digitville",
           Parse::intVecBracketed,  // input: [0,1,1,0]
           Parse::intVecBracketed,  // output: [0, 1]
           [](auto d) { return Solution().getSneakyNumbers(d); });
}
