#include "runner.h"
#include "problems/2000-2999/2958.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2958", "Length of Longest Subarray With at Most K Frequency",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().maxSubarrayLength(p.first, p.second)}; });
}
