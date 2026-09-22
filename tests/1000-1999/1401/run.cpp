#include "runner.h"
#include "problems/1000-1999/1401.cpp"

struct CheckOverlapArgs {
  int radius, xCenter, yCenter, x1, y1, x2, y2;
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1401",
      "Circle and Rectangle Overlapping",
      [](istream& in) -> CheckOverlapArgs {
        CheckOverlapArgs a;
        in >> a.radius >> a.xCenter >> a.yCenter >> a.x1 >> a.y1 >> a.x2 >> a.y2;
        return a;
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto a) {
        return vector<bool>{Solution().checkOverlap(a.radius, a.xCenter, a.yCenter, a.x1, a.y1, a.x2, a.y2)};
      }
  );
}
