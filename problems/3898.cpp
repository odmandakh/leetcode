#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> findDegrees(vector<vector<int>>& matrix) {
    int sz = matrix[0].size();
    vector<int> ans(sz, 0);

    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        ans[i] += matrix[i][j];
      }
    }

    return ans;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3898", "Find the Degree of Each Vertex",
           Parse::int2DVecBracketed,  // input: [[0,1,1],[1,0,1],...]
           Parse::intVecBracketed,    // output: [2,2,2]
           [](auto d) { return Solution().findDegrees(d); });
}
