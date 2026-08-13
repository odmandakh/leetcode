#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int differenceOfSums(int n, int m) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % m == 0) {
        sum -= i;
      } else {
        sum += i;
      }
    }
    return sum;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2894", "Divisible and Non-divisible Sums Difference",
      [](istream& in) -> pair<int, int> {
        int n = 0, m = 0;
        in >> n >> m;
        return {n, m};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().differenceOfSums(p.first, p.second)}; });
}
