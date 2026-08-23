#include <string>
#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: user's formula didn't implement the actual pairing-strategy game
// theory; provided the correct algorithm
class Solution {
 public:
  bool sumGame(string num) {
    int n = num.length();
    int leftSum = 0, leftCnt = 0, rightSum = 0, rightCnt = 0;

    for (int i = 0; i < n / 2; i++) {
      if (num[i] == '?')
        leftCnt++;
      else
        leftSum += num[i] - '0';
    }
    for (int i = n / 2; i < n; i++) {
      if (num[i] == '?')
        rightCnt++;
      else
        rightSum += num[i] - '0';
    }

    int cnt = leftCnt + rightCnt;
    if (cnt % 2 == 1) return true;

    int diff = leftSum - rightSum;
    return diff != (rightCnt - leftCnt) / 2 * 9;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1927", "Sum Game",
           Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
           Parse::boolVec,       // output: true/false
           [](auto num) { return vector<bool>{Solution().sumGame(num)}; });
}
