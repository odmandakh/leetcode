#include "runner.h"
#include "problems/4000-4999/4020.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4020",
      "Elevator Requests I",
      [](istream& in) -> pair<int, vector<int>> {
        int n = 0;
        in >> n;
        auto nums = Parse::intVecBracketed(in);
        return {n, nums};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().elevatorRequests(p.first, p.second)}; }
  );
}
