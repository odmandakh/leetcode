#include <climits>
#include <string>


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

