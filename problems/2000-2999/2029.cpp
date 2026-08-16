#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  bool stoneGameIX(vector<int>& stones) {
    int cnt[3] = {0, 0, 0};
    for (int s : stones) cnt[s % 3]++;

    if (cnt[0] % 2 == 0) {
      return cnt[1] >= 1 && cnt[2] >= 1;
    }

    return abs(cnt[1] - cnt[2]) > 2;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/2000-2999/2029", "Stone Game IX", Parse::intVecBracketed,
           Parse::boolVec,  // output: true/false
           [](auto d) { return vector<bool>{Solution().stoneGameIX(d)}; });
}
