#include "runner.h"
#include "problems/2000-2999/2338.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2338",
      "Count the Number of Ideal Arrays",
      [](istream& in) -> pair<int, int> {
        int a = 0, b = 0;
        in >> a >> b;
        return {a, b};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().idealArrays(p.first, p.second)}; }
  );
}
