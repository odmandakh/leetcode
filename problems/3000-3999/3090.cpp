#include <string>
#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: sliding-window solution written by Claude after direct request,
// not solved independently.
class Solution {
 public:
  int maximumLengthSubstring(string s) {
    vector<int> freq(26, 0);
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
      freq[s[right] - 'a']++;
      while (freq[s[right] - 'a'] > 2) {
        freq[s[left] - 'a']--;
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3090",
      "Maximum Length Substring With Two Occurrences",
      [](istream& in) -> string {
        string s;
        in >> s;
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
        return s;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().maximumLengthSubstring(s)}; });
}
