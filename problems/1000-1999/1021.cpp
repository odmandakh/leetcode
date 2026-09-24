#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  string removeOuterParentheses(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        i++;
        int valid = 1;

        while (i < s.size()) {
          if (s[i] == '(')
            valid++;
          else
            valid--;

          if (valid == 0)
            break;
          else
            ans += s[i];

          i++;
        }
      }
    }

    return ans;
  }
};
