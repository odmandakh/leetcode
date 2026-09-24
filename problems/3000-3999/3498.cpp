#include <string>

using namespace std;

class Solution {
 public:
  int reverseDegree(string s) {
    int ans = 0;

    for (int i = 1; i <= (int)s.length(); ++i) {
      ans += i * (26 - s[i - 1] + 'a');
    }

    return ans;
  }
};
