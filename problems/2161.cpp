//
// Created by Odmandakh Battulga on 2026.06.08.
//

#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> less, equal, greater;
    for (int num : nums) {
      if (num < pivot)
        less.push_back(num);
      else if (num == pivot)
        equal.push_back(num);
      else
        greater.push_back(num);
    }
    // Concatenate the three vectors
    less.insert(less.end(), equal.begin(), equal.end());
    less.insert(less.end(), greater.begin(), greater.end());
    return less;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2161",
      "Problem 2161 · Partition Array According to Given Pivot",
      // parseInput: line 1 = [a,b,c,...], line 2 = pivot
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int pivot = 0;
        in >> pivot;
        return {nums, pivot};
      },
      Parse::intVec,  // output: space-separated ints
      [](auto p) { return Solution().pivotArray(p.first, p.second); });
}
