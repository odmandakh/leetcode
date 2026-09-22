#include "runner.h"
#include "problems/0-999/38.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/38",
      "Count and Say",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::strVec,  // output: single string (as a 1-element vector)
      [](auto n) { return vector<string>{Solution().countAndSay(n)}; }
  );
}
