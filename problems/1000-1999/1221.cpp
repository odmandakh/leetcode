#include <string>

using namespace std;

class Solution {
 public:
  int balancedStringSplit(string s) {
    int i = 0, countR = 0, countL = 0, ans = 0;
    while (i < (int)s.size()) {
      if (s[i] == 'R') {
        countR++;
      } else {
        countL++;
      }

      if (countR == countL) {
        ans++;
        countR = 0;
        countL = 0;
      }

      i++;
    }

    return ans;
  }
};
