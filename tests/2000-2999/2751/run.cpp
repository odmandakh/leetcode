#include <tuple>

#include "runner.h"
#include "problems/2000-2999/2751.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2751", "Robot Collisions",
      [](istream& in) -> tuple<vector<int>, vector<int>, string> {
        auto positions = Parse::intVecBracketed(in);
        auto healths = Parse::intVecBracketed(in);
        string directions = Parse::quotedString(in);
        return {positions, healths, directions};
      },
      Parse::intVecBracketed,
      [](auto t) {
        auto& [positions, healths, directions] = t;
        return Solution().survivedRobotsHealths(positions, healths, directions);
      });
}
