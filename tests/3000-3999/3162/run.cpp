#include "runner.h"
#include "problems/3000-3999/3162.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3162", "Find the Number of Good Pairs I",
      [](istream& in) -> tuple<vector<int>, vector<int>, int> {
        auto nums1 = Parse::intVecBracketed(in);
        auto nums2 = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums1, nums2, k};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto t) {
        return vector<int>{Solution().numberOfPairs(get<0>(t), get<1>(t), get<2>(t))};
      });
}
