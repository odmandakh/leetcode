#include "runner.h"
#include "problems/2000-2999/2325.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2325", "Decode the Message",
      [](istream& in) -> pair<string, string> {
        string key = Parse::quotedLine(in);
        string message = Parse::quotedLine(in);
        return {key, message};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto p) { return vector<string>{Solution().decodeMessage(p.first, p.second)}; });
}
