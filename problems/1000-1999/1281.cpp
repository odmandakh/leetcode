#include "runner.h"

using namespace std;

class Solution {
 public:
  int subtractProductAndSum(int n) {
    int product = 1;
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      product *= digit;
      sum += digit;
      n /= 10;
    }
    return product - sum;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1281",
      "Subtract the Product and Sum of Digits of an Integer",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().subtractProductAndSum(n)}; });
}
