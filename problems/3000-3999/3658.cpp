#include <numeric>
#include <vector>


using namespace std;

class Solution {
 public:
  int gcdOfOddEvenSums(int n) {
    int oddSum = 0;
    int evenSum = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
      oddSum += i;
      evenSum += i + 1;
    }
    return gcd(oddSum, evenSum);
  }
};

