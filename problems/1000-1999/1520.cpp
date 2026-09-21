#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
  string s;
  int firstOcc[26], lastOcc[26];

  // Finds valid (all-occurrences-contained) substrings within s[l..r] and
  // appends them to picks, always preferring to decompose into smaller
  // nested valid pieces over taking one larger enclosing piece (strictly
  // more pieces, and per the problem's tie-break, smaller total length).
  void solveRange(int l, int r, vector<pair<int, int>>& picks) {
    int i = l;
    while (i <= r) {
      int c = s[i] - 'a';
      if (firstOcc[c] != i) {
        ++i;
        continue;
      }
      int end = lastOcc[c];
      int j = i;
      bool ok = true;
      while (j <= end) {
        int cj = s[j] - 'a';
        if (firstOcc[cj] < i) {
          ok = false;
          break;
        }
        end = max(end, lastOcc[cj]);
        ++j;
      }
      if (!ok) {
        ++i;
        continue;
      }

      size_t before = picks.size();
      if (i + 1 <= end - 1) solveRange(i + 1, end - 1, picks);
      if (picks.size() == before) picks.push_back({i, end});
      i = end + 1;
    }
  }

 public:
  vector<string> maxNumOfSubstrings(string str) {
    s = str;
    int n = s.size();
    fill(firstOcc, firstOcc + 26, -1);
    fill(lastOcc, lastOcc + 26, -1);
    for (int i = 0; i < n; ++i) {
      int c = s[i] - 'a';
      if (firstOcc[c] == -1) firstOcc[c] = i;
      lastOcc[c] = i;
    }

    vector<pair<int, int>> picks;
    solveRange(0, n - 1, picks);

    vector<string> result;
    for (auto& p : picks) result.push_back(s.substr(p.first, p.second - p.first + 1));
    return result;
  }
};
