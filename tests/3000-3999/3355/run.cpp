#include "runner.h"
#include "problems/3000-3999/3355.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3355", "Zero Array Transformation I",
      [](istream& in) -> pair<vector<int>, vector<vector<int>>> {
        auto nums = Parse::intVecBracketed(in);
        auto queries = Parse::int2DVecBracketed(in);
        return {nums, queries};
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto p) { return vector<bool>{Solution().isZeroArray(p.first, p.second)}; });
}
