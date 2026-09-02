#include "runner.h"
#include "problems/2000-2999/2161.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2161",
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
