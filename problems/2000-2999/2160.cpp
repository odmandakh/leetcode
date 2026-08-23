#include <algorithm>
#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int minimumSum(int num) {
    vector<int> d;
    while (num) {
      d.push_back(num % 10);
      num /= 10;
    }

    sort(d.begin(), d.end());
    return d[0] * 10 + d[2] + d[1] * 10 + d[3];
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2160",
      "Minimum Sum of Four Digit Number After Splitting Digits",
      [](istream& in) -> int {
        int num = 0;
        in >> num;
        return num;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto num) { return vector<int>{Solution().minimumSum(num)}; });
}
