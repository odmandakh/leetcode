#include <string>
#include <vector>


using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  bool isPalindromic(string s) {
    string bin;
    for (char c : s) {
      for (int bit = 7; bit >= 0; --bit) {
        bin += ((c >> bit) & 1) ? '1' : '0';
      }
    }

    int n = bin.size();
    for (int i = 0; i < n / 2; ++i) {
      if (bin[i] != bin[n - 1 - i]) return false;
    }
    return true;
  }
};

