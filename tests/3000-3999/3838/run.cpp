#include "runner.h"
#include "problems/3000-3999/3838.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3838", "Weighted Word Mapping",
      [](istream& in) -> pair<vector<string>, vector<int>> {
        auto words = Parse::strVecBracketed(in);
        auto weights = Parse::intVecBracketed(in);
        return {words, weights};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto p) { return vector<string>{Solution().mapWordWeights(p.first, p.second)}; });
}
