#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int numberOfMatches(int n) { return n - 1; }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1688", "Count of Matches in Tournament",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().numberOfMatches(n)}; });
}
