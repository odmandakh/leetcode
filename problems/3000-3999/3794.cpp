#include <string>

using namespace std;

class Solution {
 public:
  string reversePrefix(string s, int k) {
    string ans = s;

    for (int i = 0; i < k; ++i) {
      ans[i] = s[k - i - 1];
    }

    for (int i = k; i < s.length(); ++i) {
      ans[i] = s[i];
    }

    return ans;
  }
};
