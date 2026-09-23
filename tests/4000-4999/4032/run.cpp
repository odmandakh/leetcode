#include "runner.h"
#include "problems/4000-4999/4032.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4032",
      "Longest Subarray With at Most K Distinct Prime Factors",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int x = 0;
        in >> x;
        return {nums, x};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().longestSubarray(p.first, p.second)}; }
  );
}
