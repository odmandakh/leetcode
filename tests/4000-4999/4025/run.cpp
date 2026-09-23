#include <tuple>

#include "runner.h"
#include "problems/4000-4999/4025.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4025",
      "Minimize the Maximum Waiting Time at Synchronized Traffic Lights",
      [](istream& in) -> tuple<int, vector<int>, vector<int>> {
        int period = 0;
        in >> period;
        auto lights = Parse::intVecBracketed(in);
        auto arrivalTime = Parse::intVecBracketed(in);
        return {period, lights, arrivalTime};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto t) {
        auto& [period, lights, arrivalTime] = t;
        return vector<int>{Solution().minPenalty(period, lights, arrivalTime)};
      });
}
