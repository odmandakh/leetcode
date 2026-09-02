#include <string>


using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int maximumGap(string skill, string station) {
    int n = skill.size(), m = station.size();
    vector<int> leftmost(n), rightmost(n);

    for (int i = 0, j = 0; i < n; ++i) {
      while (station[j] != skill[i]) ++j;
      leftmost[i] = j++;
    }

    for (int i = n - 1, j = m - 1; i >= 0; --i) {
      while (station[j] != skill[i]) --j;
      rightmost[i] = j--;
    }

    int maxGap = 0;
    for (int i = 0; i + 1 < n; ++i) {
      maxGap = max(maxGap, rightmost[i + 1] - leftmost[i]);
    }
    return maxGap;
  }
};

