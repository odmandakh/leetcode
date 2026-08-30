#include "runner.h"
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] < nums[b]; });

    // Swappable pairs form a graph where sorted-adjacent values within
    // `limit` are connected; grouping contiguous runs in sorted order
    // captures each connected component without needing a separate DSU.
    vector<int> result(n);
    int i = 0;
    while (i < n) {
      int j = i;
      while (j + 1 < n && nums[idx[j + 1]] - nums[idx[j]] <= limit) j++;

      vector<int> groupIndices(idx.begin() + i, idx.begin() + j + 1);
      sort(groupIndices.begin(), groupIndices.end());
      for (int k = 0; k < (int)groupIndices.size(); ++k) {
        result[groupIndices[k]] = nums[idx[i + k]];
      }

      i = j + 1;
    }
    return result;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2948",
      "Make Lexicographically Smallest Array by Swapping Elements",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int limit = 0;
        in >> limit;
        return {nums, limit};
      },
      Parse::intVec,  // output: space-separated ints
      [](auto p) { return Solution().lexicographicallySmallestArray(p.first, p.second); }
  );
}
