#include "runner.h"
#include "contests/Biweekly Contest/189/Q2.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Biweekly Contest/189/tests/Q2", "Biweekly Contest 189 - Q2",
      [](istream& in) -> string {
        string s;
        in >> s;
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
        return s;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().minOperations(s)}; });
}
