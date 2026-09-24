#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPermutationDifference(string s, string t) {
    int diff = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      for (int j = 0; j < (int)t.size(); ++j) {
        if (s[i] == t[j]) {
          diff += abs(i - j);
          break;
        }
      }
    }

    return diff;
  }
};
