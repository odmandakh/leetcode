#include "runner.h"
#include "problems/1000-1999/1927.cpp"

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1927", "Sum Game",
           Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
           Parse::boolVec,       // output: true/false
           [](auto num) { return vector<bool>{Solution().sumGame(num)}; });
}
