#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  // TODO: implement
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Biweekly Contest 189/tests/Q4",
      "Biweekly Contest 189 - Q4",
      Parse::intVec,                              // TODO: pick parser
      Parse::intVec,                              // TODO: pick parser
      [](auto d) { return Solution().TODO(d); }   // TODO: solve
  );
}
