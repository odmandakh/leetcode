#include <algorithm>

using namespace std;

class Solution {
 public:
  double angleClock(int hour, int minutes) {
    double minAngle = minutes * 6.0;
    if (hour >= 12) hour -= 12;
    double hourAngle = hour * 30.0 + minutes * 0.5;

    return min(max(minAngle, hourAngle) - min(minAngle, hourAngle),
               360 - (max(minAngle, hourAngle) - min(minAngle, hourAngle)));
  }
};
