#include <numeric>
#include <vector>


using namespace std;

// ASSISTED: AI provided the binary-search + inclusion-exclusion solution logic directly.
class Solution {
 public:
  long long findKthSmallest(vector<int>& coins, int k) {
    int n = coins.size();

    // count(x) = how many amounts in [1, x] are reachable by ANY single coin,
    // via inclusion-exclusion over subsets of coins (using LCMs).
    auto count = [&](long long x) -> long long {
      long long total = 0;
      for (int mask = 1; mask < (1 << n); ++mask) {
        long long lcmVal = 1;
        int bits = __builtin_popcount(mask);
        bool overflow = false;
        for (int i = 0; i < n; ++i) {
          if (mask & (1 << i)) {
            long long g = gcd(lcmVal, (long long)coins[i]);
            long long next = lcmVal / g * coins[i];
            if (next > x) {
              overflow = true;
              break;
            }
            lcmVal = next;
          }
        }
        if (overflow) continue;
        long long term = x / lcmVal;
        total += (bits % 2 == 1) ? term : -term;
      }
      return total;
    };

    long long lo = 1, hi = (long long)*min_element(coins.begin(), coins.end()) * k;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (count(mid) >= k)
        hi = mid;
      else
        lo = mid + 1;
    }
    return lo;
  }
};

