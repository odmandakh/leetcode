#include "runner.h"
#include "contests/Biweekly Contest/189/Q1.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Biweekly Contest/189/tests/Q1", "Biweekly Contest 189 - Q1",
      [](istream& in) -> pair<int, vector<int>> {
        int n = 0;
        in >> n;
        auto requests = Parse::intVecBracketed(in);
        return {n, requests};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().elevatorRequests(p.first, p.second)}; });
}
