#include "runner.h"
#include "problems/2000-2999/2469.cpp"

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
