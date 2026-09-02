#include "runner.h"
#include "problems/2000-2999/2948.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2948",
      "Make Lexicographically Smallest Array by Swapping Elements",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int limit = 0;
        in >> limit;
        return {nums, limit};
      },
      Parse::intVec,  // output: space-separated ints
      [](auto p) { return Solution().lexicographicallySmallestArray(p.first, p.second); }
  );
}
