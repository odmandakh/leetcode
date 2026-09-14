#include "runner.h"
#include "problems/2000-2999/2798.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2798",
      "Number of Employees Who Met the Target",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int x = 0;
        in >> x;
        return {nums, x};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().numberOfEmployeesWhoMetTarget(p.first, p.second)}; }
  );
}
