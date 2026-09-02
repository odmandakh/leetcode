#include "runner.h"
#include "problems/3000-3999/3280.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3280", "Convert Date to Binary", Parse::quotedString,
      [](istream& in) -> vector<string> { return {Parse::quotedString(in)}; },
      [](auto date) { return vector<string>{Solution().convertDateToBinary(date)}; });
}
