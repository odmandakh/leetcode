#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long sum = 0;
    long long minPref = 0, maxPref = 0;
    for (int diff : differences) {
      sum += diff;
      minPref = min(minPref, sum);
      maxPref = max(maxPref, sum);
    }

    long long left = lower - minPref;
    long long right = upper - maxPref;

    return max(0LL, right - left + 1);
  }
};
