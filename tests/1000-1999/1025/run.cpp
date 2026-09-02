#include "runner.h"
#include "problems/1000-1999/1025.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1025", "Divisor Game",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector)
      [](auto n) { return vector<bool>{Solution().divisorGame(n)}; });
}
