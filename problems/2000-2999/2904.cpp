#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  string shortestBeautifulSubstring(string s, int k) {
    string smallest = "";
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '1') {
        int cnt = 0;
        string beauty = "";
        for (int j = i; j < s.length(); ++j) {
          beauty.push_back(s[j]);
          if (s[j] == '1') cnt++;
          if (cnt == k) break;
        }

        if (cnt != k) break;

        if (smallest.empty() || beauty.size() < smallest.size() ||
            (beauty.size() == smallest.size() && beauty < smallest)) {
          smallest = beauty;
        }
      }
    }

    return smallest;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2904",
      "Shortest and Lexicographically Smallest Beautiful String",
      [](istream& in) -> pair<string, int> {
        string s = Parse::quotedString(in);
        int k = 0;
        in >> k;
        return {s, k};
      },
      [](istream& in) -> vector<string> { return {Parse::quotedString(in)}; },
      [](auto p) {
        return vector<string>{Solution().shortestBeautifulSubstring(p.first, p.second)};
      });
}
