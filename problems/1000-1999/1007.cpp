#include <vector>

using namespace std;

class Solution {
 public:
  int check(int x, vector<int>& tops, vector<int>& bottoms) {
    int rotations_top = 0, rotations_bottom = 0;
    int n = tops.size();

    for (int i = 0; i < n; ++i) {
      if (tops[i] != x && bottoms[i] != x)
        return -1;
      else if (tops[i] != x)
        rotations_top++;
      else if (bottoms[i] != x)
        rotations_bottom++;
    }

    return min(rotations_top, rotations_bottom);
  }

  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int res = check(tops[0], tops, bottoms);
    if (res != -1 || tops[0] == bottoms[0])
      return res;
    else
      return check(bottoms[0], tops, bottoms);
  }
};
