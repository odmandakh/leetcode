#include <string>
#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    return (s + s).find(goal) != string::npos;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/796", "Rotate String",
      [](istream& in) -> pair<string, string> {
        auto stripQuotes = [](string s) {
          if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
          return s;
        };
        string s, goal;
        in >> s >> goal;
        return {stripQuotes(s), stripQuotes(goal)};
      },
      Parse::boolVec,  // output: true/false (as a 1-element vector)
      [](auto p) { return vector<bool>{Solution().rotateString(p.first, p.second)}; });
}
