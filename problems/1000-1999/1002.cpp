#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<char> ans(words[0].begin(), words[0].end());
    words.erase(words.begin());

    int i = 0;
    while (i < (int)ans.size()) {
      int j = 0;
      while (j < (int)words.size()) {
        int k = 0;
        for (; k < (int)words[j].size(); ++k) {
          if (words[j][k] == ans[i]) {
            break;
          }
        }

        if (k != (int)words[j].size())
          words[j].erase(k, 1);
        else
          break;

        j++;
      }

      if (j == (int)words.size())
        i++;
      else
        ans.erase(ans.begin() + i);
    }

    vector<string> result;
    for (char c : ans) {
      result.push_back(string(1, c));
    }

    return result;
  }
};
