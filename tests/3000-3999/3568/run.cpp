#include "runner.h"
#include "problems/3000-3999/3568.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3568", "Minimum Moves to Clean the Classroom",
      [](istream& in) -> pair<vector<string>, int> {
        auto classroom = Parse::strVecBracketed(in);
        int energy = 0;
        in >> energy;
        return {classroom, energy};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().minMoves(p.first, p.second)}; });
}
