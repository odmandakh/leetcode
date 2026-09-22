#include "runner.h"
#include "problems/2000-2999/2942.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2942", "Find Words Containing Character",
      [](istream& in) -> pair<vector<string>, char> {
        auto words = Parse::strVecBracketed(in);
        string x = Parse::quotedString(in);
        return {words, x[0]};
      },
      Parse::intVecBracketed,
      [](auto p) { return Solution().findWordsContaining(p.first, p.second); });
}
