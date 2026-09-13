#include <unordered_map>
#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int n = img1.size();
    vector<pair<int, int>> onesA, onesB;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (img1[r][c] == 1) onesA.emplace_back(r, c);
        if (img2[r][c] == 1) onesB.emplace_back(r, c);
      }
    }

    unordered_map<long long, int> shiftCount;
    int best = 0;
    for (auto& a : onesA) {
      for (auto& b : onesB) {
        long long dr = a.first - b.first;
        long long dc = a.second - b.second;
        long long key = dr * 1000 + dc;  // n <= 30, so deltas fit safely in this encoding
        int c = ++shiftCount[key];
        best = max(best, c);
      }
    }
    return best;
  }
};
