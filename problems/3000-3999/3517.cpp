#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  string smallestPalindrome(string s) {
    int cnt[26] = {0};
    int sz = s.length(), i = 0;
    string res = "";

    while (i < sz / 2) {
      cnt[int(s[i]) - 97]++;

      i++;
    }

    for (int j = 0; j < 26; ++j) {
      for (int k = 0; k < cnt[j]; ++k) {
        res += char(j + 97);
      }
    }

    if (sz % 2) res += s[i];

    for (int j = 25; j >= 0; --j) {
      for (int k = 0; k < cnt[j]; ++k) {
        res += char(j + 97);
      }
    }

    return res;
  }
};
