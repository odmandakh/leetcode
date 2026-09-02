#include <tuple>
#include <vector>


using namespace std;

class Solution {
 public:
  int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    for (int& num2 : nums2) {
      num2 *= k;
    }

    int cnt = 0;
    for (int num1 : nums1) {
      for (int num2 : nums2) {
        if (!(num1 % num2)) cnt++;
      }
    }

    return cnt;
  }
};

