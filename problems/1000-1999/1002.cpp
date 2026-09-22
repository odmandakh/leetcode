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
    while (i < ans.size()) {
      int j = 0;
      while (j < words.size()) {
        int k = 0;
        for (; k < words[j].size(); ++k) {
          if (words[j][k] == ans[i]) {
            break;
          }
        }

        if (k != words[j].size())
          words[j].erase(k, 1);
        else
          break;

        j++;
      }

      if (j == words.size())
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
