#include "runner.h"
#include "contests/Weekly Contest/515/Q2.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/515/tests/Q2", "Weekly Contest 515 - Q2",
      [](istream& in) -> tuple<int, vector<int>, vector<int>> {
        int period = 0;
        in >> period;
        auto lights = Parse::intVecBracketed(in);
        auto arrivalTime = Parse::intVecBracketed(in);
        return {period, lights, arrivalTime};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto t) {
        auto [period, lights, arrivalTime] = t;
        return vector<int>{Solution().minPenalty(period, lights, arrivalTime)};
      });
}
