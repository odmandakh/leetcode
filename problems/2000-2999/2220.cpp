#include <vector>


using namespace std;

class Solution {
 public:
  int minBitFlips(int start, int goal) {
    int xor_result = start ^ goal;
    int count = 0;
    while (xor_result) {
      count += xor_result & 1;
      xor_result >>= 1;
    }
    return count;
  }
};

