#include <string>

using namespace std;

class Solution {
 public:
  int scoreOfString(string s) {
    int sum = 0;
    while (s.size() > 1) {
      sum += abs(s[0] - s[1]);
      s.erase(0, 1);
    }

    return sum;
  }
};
