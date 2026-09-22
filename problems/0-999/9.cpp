#include <algorithm>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    int temp = max(x, 0);
    long long int y = 0;
    while (temp) {
      y *= 10;
      y += temp % 10;

      temp /= 10;
    }

    return x == y ? true : false;
  }
};
