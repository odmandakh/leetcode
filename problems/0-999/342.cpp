#include <algorithm>

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int n) {
    n = max(n, 0);
    if (!n) return false;

    while (n != 1) {
      if (n % 4) return false;

      n /= 4;
    }

    return true;
  }
};
