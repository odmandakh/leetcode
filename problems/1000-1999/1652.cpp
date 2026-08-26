#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    vector<int> decryptedCode(code.size(), 0);
    int n = code.size();

    for (int i = 0; i < n; ++i) {
      if (k == 0) break;

      int sum = 0;
      int it = i;
      for (int j = 0; j < abs(k); ++j) {
        it += (k > 0) ? 1 : -1;
        it = (it + n) % n;
        sum += code[it];
      }

      decryptedCode[i] = sum;
    }

    return decryptedCode;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1652", "Defuse the Bomb",
      [](istream& in) -> pair<vector<int>, int> {
        auto code = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {code, k};
      },
      Parse::intVecBracketed,  // output: [1,2,3,...]
      [](auto p) { return Solution().decrypt(p.first, p.second); });
}
