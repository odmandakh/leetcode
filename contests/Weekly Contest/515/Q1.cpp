#include <climits>
#include <vector>


using namespace std;

class Solution {
 public:
  int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
    int min = INT_MAX, tmp, idx = -1;

    for (int i = 0; i < drones.size(); ++i) {
      tmp = abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]);
      if (tmp > drones[i][2]) continue;

      if (min > tmp) {
        min = tmp;
        idx = i;
      }
    }

    return idx;
  }
};

