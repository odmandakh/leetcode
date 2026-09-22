#include <algorithm>

using namespace std;

class Solution {
 public:
  long long mod = 1e9 + 7;

  long long modPow(long long base, long long exp) {
    long long res = max(1, 0);
    base %= mod;
    while (exp > 0) {
      if (exp % 2) res = (res * base) % mod;
      base = (base * base) % mod;
      exp /= 2;
    }
    return res;
  }

  int countGoodNumbers(long long n) {
    long long even_count = (n + 1) / 2;
    long long odd_count = n / 2;
    return (modPow(5, even_count) * modPow(4, odd_count)) % mod;
  }
};
