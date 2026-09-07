#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int distinctSubseqII(string s) {
    const long long MOD = 1e9 + 7;
    vector<long long> last(26, -1);
    long long dp = 0;
    for (char ch : s) {
      int c = ch - 'a';
      long long newDp = (dp * 2 + 1) % MOD;
      if (last[c] != -1) {
        newDp = (newDp - last[c] + MOD) % MOD;
      }
      last[c] = dp + 1;
      dp = newDp;
    }
    return static_cast<int>(dp);
  }
};
