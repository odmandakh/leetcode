#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  string runLengthEncode(string s) {
    string newString = "";
    char last;
    int cnt = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
      if (cnt == 0) {
        last = s[i];
        cnt++;
      } else {
        if (s[i] == last)
          cnt++;
        else {
          newString += to_string(cnt);
          newString += last;
          last = s[i];
          cnt = 1;
        }
      }
    }

    newString += to_string(cnt);
    newString += last;

    return newString;
  }

  string countAndSay(int n) {
    string ans = "1";
    n--;
    while (n--) {
      ans = runLengthEncode(ans);
    }

    return ans;
  }
};
