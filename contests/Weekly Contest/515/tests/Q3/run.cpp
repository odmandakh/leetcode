#include "runner.h"
#include "contests/Weekly Contest/515/Q3.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/515/tests/Q3", "Weekly Contest 515 - Q3",
      [](istream& in) -> pair<string, string> {
        auto stripQuotes = [](string s) {
          if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
          return s;
        };
        string skill, station;
        in >> skill >> station;
        return {stripQuotes(skill), stripQuotes(station)};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().maximumGap(p.first, p.second)}; });
}
