#include "runner.h"

using namespace std;

class Solution {
 public:
  int digitFrequencyScore(int n) {
    int score = 0;
    while (n > 0) {
      score += n % 10;
      n /= 10;
    }
    return score;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3945", "Digit Frequency Score",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto n) { return vector<int>{Solution().digitFrequencyScore(n)}; });
}
