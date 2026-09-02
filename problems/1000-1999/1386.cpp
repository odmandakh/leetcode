#include <unordered_map>
#include <vector>


using namespace std;

// ASSISTED: hash-map rewrite by Claude after direct request (n can be up to
// 10^9, so an n-sized array is infeasible -- only rows with an actual
// reservation need tracking), not solved independently.
class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> rowMask;  // row -> bitmask of reserved seats (bit i = seat i+1)
    for (auto& seat : reservedSeats) {
      int row = seat[0], col = seat[1];
      rowMask[row] |= (1 << (col - 1));
    }

    // Every row with no reservation at all trivially fits 2 families.
    long long total = 2LL * (n - (long long)rowMask.size());

    int leftMask = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);   // seats 2-5
    int midMask = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);    // seats 4-7
    int rightMask = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);  // seats 6-9

    for (auto& [row, mask] : rowMask) {
      bool leftFree = (mask & leftMask) == 0;
      bool midFree = (mask & midMask) == 0;
      bool rightFree = (mask & rightMask) == 0;

      if (leftFree && rightFree) {
        total += 2;  // non-overlapping left+right blocks fit two families
      } else if (leftFree || midFree || rightFree) {
        total += 1;  // only one non-overlapping block is free
      }
    }

    return (int)total;
  }
};

