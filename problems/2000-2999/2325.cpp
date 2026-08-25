#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  string decodeMessage(string key, string message) {
    unordered_map<char, char> substitutionTable;
    int alphabetAscii = 0;
    for (char ch : key) {
      if (ch < 'a' || ch > 'z') continue;

      bool seen = false;
      for (auto [k, v] : substitutionTable) {
        if (k == ch) {
          seen = true;
          break;
        }
      }

      if (!seen) {
        substitutionTable[ch] = 'a' + alphabetAscii;
        alphabetAscii++;
      }
    }

    for (char& ch : message) {
      if (ch < 'a' || ch > 'z') continue;

      for (auto [k, v] : substitutionTable) {
        if (k == ch) {
          ch = v;
          break;
        }
      }
    }

    return message;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2325", "Decode the Message",
      [](istream& in) -> pair<string, string> {
        string key = Parse::quotedLine(in);
        string message = Parse::quotedLine(in);
        return {key, message};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto p) { return vector<string>{Solution().decodeMessage(p.first, p.second)}; });
}
