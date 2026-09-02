#include "runner.h"
#include "problems/2000-2999/2213.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2213", "Longest Substring of One Repeating Character",
      [](istream& in) -> tuple<string, string, vector<int>> {
        auto stripQuotes = [](string s) {
          if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
          return s;
        };
        string s, qc;
        in >> s >> qc;
        s = stripQuotes(s);
        qc = stripQuotes(qc);
        auto indices = Parse::intVecBracketed(in);
        return {s, qc, indices};
      },
      Parse::intVecBracketed,  // output: [3,3,4]
      [](auto t) {
        auto [s, qc, idx] = t;
        return Solution().longestRepeating(s, qc, idx);
      });
}
