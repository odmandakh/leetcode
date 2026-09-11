#include <vector>

using namespace std;

class Solution {
 public:
  int totalNumbers(vector<int>& digits) {
    int digitCnt[10] = {0};
    for (int digit : digits) {
      digitCnt[digit]++;
    }

    int ans = 0;
    for (int i = 100; i <= 998; i += 2) {
      int units = i % 10;
      int tens = (i / 10) % 10;
      int hundreds = i / 100;

      digitCnt[units]--;
      digitCnt[tens]--;
      digitCnt[hundreds]--;

      if (digitCnt[units] >= 0 && digitCnt[tens] >= 0 && digitCnt[hundreds] >= 0) ans++;

      digitCnt[units]++;
      digitCnt[tens]++;
      digitCnt[hundreds]++;
    }

    return ans;
  }
};
