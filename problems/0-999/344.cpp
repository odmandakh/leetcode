#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    vector<char> s1(s.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
      s1[i] = s[s.size() - i - 1];
    }

    s = s1;
  }
};
