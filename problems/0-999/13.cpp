#include <string>

using namespace std;

class Solution {
 public:
  int value(char r) {
    switch (r) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
      default:
        return -1;
    }
  }

  int romanToInt(string s) {
    int ans = 0, s1, s2;

    for (int i = 0; i < s.length(); i++) {
      s1 = value(s[i]);

      if (s1 == -1) return -1;

      if (i + 1 < s.length()) {
        s2 = value(s[i + 1]);

        if (s2 == -1) {
          return -1;
        }

        if (s1 < s2) {
          ans += (s2 - s1);
          i++;
          continue;
        }
      }

      ans += s1;
    }

    return ans;
  }
};
