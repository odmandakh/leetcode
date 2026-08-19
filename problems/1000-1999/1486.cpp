#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int xorOperation(int n, int start) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
      result ^= start + 2 * i;
    }
    return result;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1486", "XOR Operation in an Array",
      [](istream& in) -> pair<int, int> {
        int n = 0, start = 0;
        in >> n >> start;
        return {n, start};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().xorOperation(p.first, p.second)}; });
}
