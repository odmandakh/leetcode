#include "runner.h"
#include "problems/2000-2999/2946.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2946", "Matrix Similarity After Cyclic Shifts",
      [](istream& in) -> pair<vector<vector<int>>, int> {
        auto mat = Parse::int2DVecBracketed(in);
        int k = 0;
        in >> k;
        return {mat, k};
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto p) { return vector<bool>{Solution().areSimilar(p.first, p.second)}; });
}
