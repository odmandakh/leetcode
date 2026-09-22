#include "runner.h"
#include "problems/2000-2999/2573.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2573", "Find the String with LCP",
      Parse::int2DVecBracketed,
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto lcp) { return vector<string>{Solution().findTheString(lcp)}; });
}
