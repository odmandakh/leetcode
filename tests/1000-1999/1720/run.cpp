#include "runner.h"
#include "problems/1000-1999/1720.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1720", "Decode XORed Array",
      [](istream& in) -> pair<vector<int>, int> {
        auto encoded = Parse::intVecBracketed(in);
        int first = 0;
        in >> first;
        return {encoded, first};
      },
      Parse::intVecBracketed,  // output: [1,0,2,1]
      [](auto p) { return Solution().decode(p.first, p.second); });
}
