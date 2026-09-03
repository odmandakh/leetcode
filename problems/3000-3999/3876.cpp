#include <algorithm>
#include <vector>

using namespace std;

// TODO: There was also best solution for this T - C = C but C - T = C. So CCCCCCT is true but
// TTTTTTC is false
class Solution {
 public:
  bool uniformArray(vector<int>& nums1) {
    sort(nums1.begin(), nums1.end());

    int isOdd = nums1[0] % 2;
    for (int i = 1; i < nums1.size(); ++i) {
      if (isOdd != nums1[i] % 2) {
        bool found = false;
        for (int j = 0; j < i; ++j) {
          if (isOdd == (nums1[i] - nums1[j]) % 2) {
            found = true;
            break;
          }
        }

        if (!found) return false;
      }
    }

    return true;
  }
};
