#include <algorithm>

using namespace std;

class Solution {
 public:
  int countLargestGroup(int n) {
    int sums[37] = {0};

    for (int i = 1; i <= n; ++i) {
      int temp = i, sum = 0;
      while (temp) {
        sum += temp % 10;
        temp /= 10;
      }

      sums[sum]++;
    }

    sort(sums, sums + 37, greater<int>());

    int result = 0;
    for (int i = 0; i <= n; ++i) {
      if (sums[0] == sums[i]) {
        result++;
      } else {
        break;
      }
    }

    return result;
  }
};
