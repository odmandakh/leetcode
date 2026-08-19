#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int minBitFlips(int start, int goal) {
    int xor_result = start ^ goal;
    int count = 0;
    while (xor_result) {
      count += xor_result & 1;
      xor_result >>= 1;
    }
    return count;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2220", "Minimum Bit Flips to Convert Number",
      [](istream& in) -> pair<int, int> {
        int start = 0, goal = 0;
        in >> start >> goal;
        return {start, goal};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().minBitFlips(p.first, p.second)}; });
}
