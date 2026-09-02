#include "runner.h"
#include "problems/3000-3999/3318.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3318", "Find X-Sum of All K-Long Subarrays I",
      [](istream& in) -> tuple<vector<int>, int, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0, x = 0;
        in >> k >> x;
        return {nums, k, x};
      },
      Parse::intVecBracketed,  // output: [1,2,3,...]
      [](auto t) { return Solution().findXSum(get<0>(t), get<1>(t), get<2>(t)); });
}
