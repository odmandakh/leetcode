#include "runner.h"
#include "problems/1000-1999/1431.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1431",
      "Kids With the Greatest Number of Candies",
      [](istream& in) -> pair<vector<int>, int> {
        auto candies = Parse::intVecBracketed(in);
        int extraCandies = 0;
        in >> extraCandies;
        return {candies, extraCandies};
      },
      Parse::boolVecBracketed,  // output: [true,false,...]
      [](auto p) {
        return Solution().kidsWithCandies(p.first, p.second);
      });
}
