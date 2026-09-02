#include "runner.h"
#include "problems/3000-3999/3668.cpp"

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
