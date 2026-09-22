#include <vector>

using namespace std;

class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int count[100] = {0};
    int result = 0;

    for (auto& d : dominoes) {
      int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
      result += count[key];
      count[key]++;
    }

    return result;
  }
};
