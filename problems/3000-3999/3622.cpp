#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  bool checkDivisibility(int n) {
    int digitSum = 0, digitProduct = 1, tmp = n, digit;
    while (tmp) {
      digit = tmp % 10;
      digitSum += digit;
      digitProduct *= digit;
      tmp /= 10;
    }
    return n % (digitProduct + digitSum) == 0;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3622", "Check Divisibility by Digit Sum and Product",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::boolVec,  // output: true/false
      [](auto n) { return vector<bool>{Solution().checkDivisibility(n)}; });
}
