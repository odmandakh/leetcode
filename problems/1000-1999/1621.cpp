#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
  static long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
      if (exp & 1) result = result * base % mod;
      base = base * base % mod;
      exp >>= 1;
    }
    return result;
  }

 public:
  int numberOfSets(int n, int k) {
    const long long MOD = 1000000007;
    // Closed form: choosing k non-overlapping (touching-allowed) segments from
    // n points is equivalent to choosing 2k values with repetition from
    // n+k-1 options, i.e. C(n+k-1, 2k).
    int top = n + k - 1;
    int bottom = 2 * k;

    vector<long long> fact(top + 1);
    fact[0] = 1;
    for (int i = 1; i <= top; ++i) fact[i] = fact[i - 1] * i % MOD;

    long long invBottom = power(fact[bottom], MOD - 2, MOD);
    long long invRest = power(fact[top - bottom], MOD - 2, MOD);

    long long ans = fact[top] * invBottom % MOD * invRest % MOD;
    return (int)ans;
  }
};
