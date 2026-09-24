#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string ans = strs[0];

    for (string str : strs) {
      int i = 0;
      while (i < (int)ans.size() && i < (int)str.size() && ans[i] == str[i]) {
        i++;
      }
      ans = ans.substr(0, i);

      if (ans.empty()) return "";
    }

    return ans;
  }
};
