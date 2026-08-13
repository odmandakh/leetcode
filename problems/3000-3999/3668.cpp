#include <algorithm>
#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
    vector<int> result;
    for (int i = 0; i < order.size(); ++i) {
      if (find(friends.begin(), friends.end(), order[i]) != friends.end()) {
        result.push_back(order[i]);
      }
    }
    return result;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3668", "Restore Finishing Order",
      [](istream& in) -> pair<vector<int>, vector<int>> {
        auto order = Parse::intVecBracketed(in);
        auto friends = Parse::intVecBracketed(in);
        return {order, friends};
      },
      Parse::intVecBracketed,  // output: [1,3,4]
      [](auto p) { return Solution().recoverOrder(p.first, p.second); });
}
