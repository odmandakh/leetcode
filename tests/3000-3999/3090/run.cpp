#include "runner.h"
#include "problems/3000-3999/3090.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3090",
      "Maximum Length Substring With Two Occurrences",
      [](istream& in) -> string {
        string s;
        in >> s;
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
        return s;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().maximumLengthSubstring(s)}; });
}
