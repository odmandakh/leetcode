#include <numeric>
#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int gcdOfOddEvenSums(int n) {
    int oddSum = 0;
    int evenSum = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
      oddSum += i;
      evenSum += i + 1;
    }
    return gcd(oddSum, evenSum);
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3658", "GCD of Odd and Even Sums",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().gcdOfOddEvenSums(n)}; });
}
