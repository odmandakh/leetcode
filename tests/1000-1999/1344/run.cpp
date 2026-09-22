#include "runner.h"
#include "problems/1000-1999/1344.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1344",
      "Angle Between Hands of a Clock",
      [](istream& in) -> pair<int, int> {
        int hour = 0, minutes = 0;
        in >> hour >> minutes;
        return {hour, minutes};
      },
      [](istream& in) -> vector<double> {
        // Note: this problem's angle is always a multiple of 0.5deg (integer
        // arithmetic plus minutes*0.5), which is always exactly representable
        // in IEEE754 double -- so plain equality comparison below is safe
        // here, unlike floating-point problems in general.
        double x = 0;
        in >> x;
        return {x};
      },
      [](auto p) { return vector<double>{Solution().angleClock(p.first, p.second)}; }
  );
}
