#include <climits>
#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
    int min = INT_MAX, tmp, idx = -1;

    for (int i = 0; i < drones.size(); ++i) {
      tmp = abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]);
      if (tmp > drones[i][2]) continue;

      if (min > tmp) {
        min = tmp;
        idx = i;
      }
    }

    return idx;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest 515/tests/Q1", "Weekly Contest 515 - Q1",
      [](istream& in) -> pair<vector<vector<int>>, vector<int>> {
        auto drones = Parse::int2DVecBracketed(in);
        auto target = Parse::intVecBracketed(in);
        return {drones, target};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().nearestDrone(p.first, p.second)}; });
}
