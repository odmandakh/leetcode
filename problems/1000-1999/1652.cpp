#include <vector>


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

