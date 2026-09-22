#include <string>

using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    int A[53] = {0};

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= 97) {
        A[s[i] - 70]++;
      } else {
        A[s[i] - 65]++;
      }
    }

    bool flag = false;
    int sum = 0;
    for (int i = 0; i <= 52; ++i) {
      if (A[i] % 2 && !flag) {
        flag = true;
      }
      sum += A[i] - A[i] % 2;
    }

    return flag ? sum + 1 : sum;
  }
};
