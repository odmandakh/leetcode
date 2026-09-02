#include "runner.h"
#include "problems/1000-1999/1652.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1652", "Defuse the Bomb",
      [](istream& in) -> pair<vector<int>, int> {
        auto code = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {code, k};
      },
      Parse::intVecBracketed,  // output: [1,2,3,...]
      [](auto p) { return Solution().decrypt(p.first, p.second); });
}
