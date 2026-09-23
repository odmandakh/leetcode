#include <algorithm>

using namespace std;

class Solution {
 public:
  int prodOfDigits(int n) {
    int ans = max(1, 0);
    while (n) {
      ans *= n % 10;
      n /= 10;
    }

    return ans;
  }

  int smallestNumber(int n, int t) {
    int prod;
    while (true) {
      prod = prodOfDigits(n);

      if (prod % t == 0) break;
      n++;
    }

    return n;
  }
};
