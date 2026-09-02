#include "runner.h"
#include "problems/3000-3999/3931.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3931", "Check Adjacent Digit Differences",
      [](istream& in) -> string {
        string s;
        in >> s;
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
        return s;
      },
      Parse::boolVec,  // output: true/false (as a 1-element vector)
      [](auto s) { return vector<bool>{Solution().isAdjacentDiffAtMostTwo(s)}; });
}
