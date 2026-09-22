#include <tuple>

#include "runner.h"
#include "problems/2000-2999/2145.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2145", "Count the Hidden Sequences",
      [](istream& in) -> tuple<vector<int>, int, int> {
        auto differences = Parse::intVecBracketed(in);
        int lower = 0, upper = 0;
        in >> lower >> upper;
        return {differences, lower, upper};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto t) {
        auto& [differences, lower, upper] = t;
        return vector<int>{Solution().numberOfArrays(differences, lower, upper)};
      });
}
