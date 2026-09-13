#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
  static long long reverseDigits(long long v) {
    long long r = 0;
    while (v > 0) {
      r = r * 10 + v % 10;
      v /= 10;
    }
    return r;
  }

  static long long mirrorPalindrome(long long prefix, int h, int L) {
    if (L % 2 == 0) {
      long long p10h = 1;
      for (int i = 0; i < h; ++i) p10h *= 10;
      return prefix * p10h + reverseDigits(prefix);
    } else {
      long long p10h1 = 1;
      for (int i = 0; i < h - 1; ++i) p10h1 *= 10;
      return prefix * p10h1 + reverseDigits(prefix / 10);
    }
  }

  static long long closestSameParityPalindrome(long long x) {
    int d = 0;
    for (long long t = x; t > 0; t /= 10) ++d;
    int desiredParity = x % 2;
    long long best = -1, bestDist = -1;

    auto consider = [&](long long p) {
      if (p <= 0 || (p % 2) != desiredParity) return;
      long long dist = (p > x) ? (p - x) : (x - p);
      if (bestDist == -1 || dist < bestDist) {
        bestDist = dist;
        best = p;
      }
    };

    for (int L = max(1, d - 1); L <= d + 1; ++L) {
      int h = (L + 1) / 2;
      long long lo = 1, hi = 9;
      for (int i = 1; i < h; ++i) {
        lo *= 10;
        hi = hi * 10 + 9;
      }

      long long prefix0;
      if (L == d) {
        long long divisor = 1;
        for (int i = 0; i < d - h; ++i) divisor *= 10;
        prefix0 = x / divisor;
      } else if (L < d) {
        prefix0 = hi;
      } else {
        prefix0 = lo;
      }

      for (long long delta = -1; delta <= 1; ++delta) {
        long long pp = prefix0 + delta;
        if (pp >= lo && pp <= hi) consider(mirrorPalindrome(pp, h, L));
      }

      long long leadDigit0 = prefix0 / lo;
      if (leadDigit0 - 1 >= 1) consider(mirrorPalindrome((leadDigit0 - 1) * lo + (lo - 1), h, L));
      if (leadDigit0 + 1 <= 9) consider(mirrorPalindrome((leadDigit0 + 1) * lo, h, L));
    }
    return best;
  }

 public:
  long long minOperations(vector<int>& nums) {
    long long total = 0;
    for (int x : nums) {
      long long p = closestSameParityPalindrome(x);
      total += (p - x >= 0 ? p - x : x - p) / 2;
    }
    return total;
  }
};
