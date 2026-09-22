#include <tuple>

#include "runner.h"
#include "problems/2000-2999/2071.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2071", "Maximum Number of Tasks You Can Assign",
      [](istream& in) -> tuple<vector<int>, vector<int>, int, int> {
        auto tasks = Parse::intVecBracketed(in);
        auto workers = Parse::intVecBracketed(in);
        int pills = 0, strength = 0;
        in >> pills >> strength;
        return {tasks, workers, pills, strength};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto t) {
        auto& [tasks, workers, pills, strength] = t;
        return vector<int>{Solution().maxTaskAssign(tasks, workers, pills, strength)};
      });
}
