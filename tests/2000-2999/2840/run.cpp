#include "runner.h"
#include "problems/2000-2999/2840.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2840",
      "Check if Strings Can be Made Equal With Operations II",
      [](istream& in) -> pair<string, string> {
        string s1 = Parse::quotedString(in);
        string s2 = Parse::quotedString(in);
        return {s1, s2};
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto p) { return vector<bool>{Solution().checkStrings(p.first, p.second)}; });
}
