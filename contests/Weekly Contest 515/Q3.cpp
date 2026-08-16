#include <string>

#include "runner.h"

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int maximumGap(string skill, string station) {
    int n = skill.size(), m = station.size();
    vector<int> leftmost(n), rightmost(n);

    for (int i = 0, j = 0; i < n; ++i) {
      while (station[j] != skill[i]) ++j;
      leftmost[i] = j++;
    }

    for (int i = n - 1, j = m - 1; i >= 0; --i) {
      while (station[j] != skill[i]) --j;
      rightmost[i] = j--;
    }

    int maxGap = 0;
    for (int i = 0; i + 1 < n; ++i) {
      maxGap = max(maxGap, rightmost[i + 1] - leftmost[i]);
    }
    return maxGap;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest 515/tests/Q3", "Weekly Contest 515 - Q3",
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
