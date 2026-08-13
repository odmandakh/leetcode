#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<double> convertTemperature(double celsius) {
    vector<double> result(2);
    result[0] = celsius + 273.15;
    result[1] = celsius * 1.80 + 32.00;
    return result;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2469", "Convert the Temperature",
      [](istream& in) -> double {
        double celsius = 0;
        in >> celsius;
        return celsius;
      },
      [](istream& in) -> vector<double> {
        string line;
        while (getline(in, line)) {
          if (!line.empty()) break;
        }
        for (char& c : line) {
          if (c == '[' || c == ']' || c == ',') c = ' ';
        }
        istringstream iss(line);
        vector<double> v;
        double x;
        while (iss >> x) v.push_back(x);
        return v;
      },
      [](auto celsius) { return Solution().convertTemperature(celsius); });
}
