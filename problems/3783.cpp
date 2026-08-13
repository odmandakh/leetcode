#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int mirrorDistance(int n) {
    int reversed = 0;
    int original = n;
    while (n > 0) {
      reversed = reversed * 10 + n % 10;
      n /= 10;
    }
    return abs(original - reversed);
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3783", "Mirror Distance of an Integer",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().mirrorDistance(n)}; });
}
