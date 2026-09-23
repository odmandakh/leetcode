#include <tuple>

#include "runner.h"
#include "problems/3000-3999/3516.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3516", "Find Closest Person",
      [](istream& in) -> tuple<int, int, int> {
        int x = 0, y = 0, z = 0;
        in >> x >> y >> z;
        return {x, y, z};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto t) {
        auto& [x, y, z] = t;
        return vector<int>{Solution().findClosest(x, y, z)};
      });
}
