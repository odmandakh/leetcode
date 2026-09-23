#include <tuple>

#include "runner.h"
#include "problems/4000-4999/4031.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4031", "Find All Numbers Disappeared in an Array II",
      [](istream& in) -> tuple<vector<int>, int, int> {
        auto nums = Parse::intVecBracketed(in);
        int lower = 0, upper = 0;
        in >> lower >> upper;
        return {nums, lower, upper};
      },
      Parse::int2DVecBracketed,
      [](auto t) {
        auto& [nums, lower, upper] = t;
        return Solution().findDisappearedNumbers(nums, lower, upper);
      });
}
