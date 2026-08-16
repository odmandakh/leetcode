#include <climits>
#include <string>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int minOperations(string s) {
    int n = s.size(), diff;
    int ans = INT_MAX;

    for (int i = 0; i < n; ++i) {
      int cost = i;

      for (int l = 0, r = n - 1; l < r; ++l, --r) {
        diff = abs(s[l] - s[r]);
        cost += min(diff, 26 - diff);
      }

      ans = min(ans, cost);

      rotate(s.begin(), s.begin() + 1, s.end());
    }

    return ans;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Biweekly Contest 189/tests/Q2", "Biweekly Contest 189 - Q2",
      [](istream& in) -> string {
        string s;
        in >> s;
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
        return s;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().minOperations(s)}; });
}
