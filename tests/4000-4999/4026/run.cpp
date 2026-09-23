#include "runner.h"
#include "problems/4000-4999/4026.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4026",
      "Maximum Gap Between Stations",
      [](istream& in) -> pair<string, string> {
        string a = Parse::quotedString(in);
        string b = Parse::quotedString(in);
        return {a, b};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().maximumGap(p.first, p.second)}; }
  );
}
