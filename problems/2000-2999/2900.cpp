#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    vector<string> ans;
    int groupId = -1;

    for (int i = 0; i < groups.size(); ++i)
      if (groups[i] != groupId) {
        groupId = groups[i];
        ans.push_back(words[i]);
      }

    return ans;
  }
};
