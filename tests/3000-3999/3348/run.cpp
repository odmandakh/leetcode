#include "problems/3000-3999/3348.cpp"
#include "runner.h"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3348", "Smallest Divisible Digit Product II",
      [](istream& in) -> pair<string, long long> {
        string s;
        long long t;
        in >> s >> t;
        return {s, t};
      },
      Parse::strVec,
      [](auto p) { return vector<string>{Solution().smallestNumber(p.first, p.second)}; });
}
