#include "runner.h"
#include "problems/1000-1999/1386.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1386", "Cinema Seat Allocation",
      [](istream& in) -> pair<int, vector<vector<int>>> {
        int n = 0;
        in >> n;
        auto reservedSeats = Parse::int2DVecBracketed(in);
        return {n, reservedSeats};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().maxNumberOfFamilies(p.first, p.second)}; });
}
