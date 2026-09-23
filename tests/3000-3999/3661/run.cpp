#include <tuple>

#include "runner.h"
#include "problems/3000-3999/3661.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3661", "Maximum Walls Destroyed by Robots",
      [](istream& in) -> tuple<vector<int>, vector<int>, vector<int>> {
        auto robots = Parse::intVecBracketed(in);
        auto distance = Parse::intVecBracketed(in);
        auto walls = Parse::intVecBracketed(in);
        return {robots, distance, walls};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto t) {
        auto& [robots, distance, walls] = t;
        return vector<int>{Solution().maxWalls(robots, distance, walls)};
      });
}
