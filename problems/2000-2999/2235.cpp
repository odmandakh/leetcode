#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int sum(int num1, int num2) { return num1 + num2; }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2235", "Add Two Integers",
      [](istream& in) -> pair<int, int> {
        int num1 = 0, num2 = 0;
        in >> num1 >> num2;
        return {num1, num2};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().sum(p.first, p.second)}; });
}
