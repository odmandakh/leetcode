#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int theMaximumAchievableX(int num, int t) { return num + 2 * t; }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2769", "Find the Maximum Achievable Number",
      [](istream& in) -> pair<int, int> {
        int num = 0, t = 0;
        in >> num >> t;
        return {num, t};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().theMaximumAchievableX(p.first, p.second)}; });
}
