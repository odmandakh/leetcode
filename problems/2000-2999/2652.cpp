#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int sumOfMultiples(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
        sum += i;
      }
    }
    return sum;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2652", "Sum Multiples",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().sumOfMultiples(n)}; });
}
