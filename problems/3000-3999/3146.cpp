#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int findPermutationDifference(string s, string t) {
    int diff = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < t.size(); ++j) {
        if (s[i] == t[j]) {
          diff += abs(i - j);
          break;
        }
      }
    }

    return diff;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3146", "Permutation Difference between Two Strings",
      [](istream& in) -> pair<string, string> {
        string s = Parse::quotedString(in);
        string t = Parse::quotedString(in);
        return {s, t};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().findPermutationDifference(p.first, p.second)}; });
}
