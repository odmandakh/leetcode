#include "runner.h"
#include "contests/Weekly Contest/515/Q1.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/515/tests/Q1", "Weekly Contest 515 - Q1",
      [](istream& in) -> pair<vector<vector<int>>, vector<int>> {
        auto drones = Parse::int2DVecBracketed(in);
        auto target = Parse::intVecBracketed(in);
        return {drones, target};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().nearestDrone(p.first, p.second)}; });
}
