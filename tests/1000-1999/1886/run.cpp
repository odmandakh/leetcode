#include "runner.h"
#include "problems/1000-1999/1886.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1886",
      "Determine Whether Matrix Can Be Obtained By Rotation",
      [](istream& in) -> pair<vector<vector<int>>, vector<vector<int>>> {
        auto mat = Parse::int2DVecBracketed(in);
        auto target = Parse::int2DVecBracketed(in);
        return {mat, target};
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto p) { return vector<bool>{Solution().findRotation(p.first, p.second)}; }
  );
}
