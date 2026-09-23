#include <string>

using namespace std;

class Solution {
 public:
  int minimumChairs(string s) {
    int ans = 0, chair = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'E') {
        if (chair > 0)
          chair--;
        else
          ans++;
      } else
        chair++;
    }

    return ans;
  }
};
