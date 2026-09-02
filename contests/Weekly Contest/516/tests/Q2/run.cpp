#include "runner.h"
#include "contests/Weekly Contest/516/Q2.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/516/tests/Q2", "Weekly Contest 516 - Q2",
      [](istream& in) -> tuple<vector<int>, int, int> {
        auto nums = Parse::intVecBracketed(in);
        int lower = 0, upper = 0;
        in >> lower >> upper;
        return {nums, lower, upper};
      },
      Parse::int2DVecBracketed,  // output: [[1,2],[4,6],...]
      [](auto t) {
        auto [nums, lower, upper] = t;
        return Solution().findDisappearedNumbers(nums, lower, upper);
      });
}
