#include <vector>


using namespace std;

class Solution {
 public:
  bool checkDivisibility(int n) {
    int digitSum = 0, digitProduct = 1, tmp = n, digit;
    while (tmp) {
      digit = tmp % 10;
      digitSum += digit;
      digitProduct *= digit;
      tmp /= 10;
    }
    return n % (digitProduct + digitSum) == 0;
  }
};

