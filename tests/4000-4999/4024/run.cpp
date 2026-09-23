#include "runner.h"
#include "problems/4000-4999/4024.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4024",
      "Nearest Available Drone",
      [](istream& in) -> pair<vector<vector<int>>, vector<int>> {
        auto grid = Parse::int2DVecBracketed(in);
        auto nums = Parse::intVecBracketed(in);
        return {grid, nums};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().nearestDrone(p.first, p.second)}; }
  );
}
