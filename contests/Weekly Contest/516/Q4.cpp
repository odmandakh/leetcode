#include <algorithm>
#include <cmath>
#include <numeric>
#include <tuple>
#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
    int n = nums.size();
    int q = queries.size();

    vector<int> sortedVals(nums);
    sort(sortedVals.begin(), sortedVals.end());
    sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
    vector<int> comp(n);
    for (int i = 0; i < n; ++i)
      comp[i] = lower_bound(sortedVals.begin(), sortedVals.end(), nums[i]) - sortedVals.begin();

    // Mo's algorithm: answer range queries offline in O((n+q) sqrt n) by
    // moving a [curL, curR] window one element at a time, reusing work
    // between queries that are close together.
    vector<int> order(q);
    iota(order.begin(), order.end(), 0);
    int blockSize = max(1, (int)(n / max(1.0, sqrt((double)q))));
    sort(order.begin(), order.end(), [&](int a, int b) {
      int blockA = queries[a][0] / blockSize, blockB = queries[b][0] / blockSize;
      if (blockA != blockB) return blockA < blockB;
      return (blockA & 1) ? queries[a][1] > queries[b][1] : queries[a][1] < queries[b][1];
    });

    vector<int> freq(sortedVals.size(), 0);
    int distinctCount = 0, oddFreqCount = 0;
    auto add = [&](int pos) {
      int v = comp[pos];
      if (freq[v] == 0) distinctCount++;
      freq[v]++;
      oddFreqCount += (freq[v] & 1) ? 1 : -1;
    };
    auto remove = [&](int pos) {
      int v = comp[pos];
      freq[v]--;
      oddFreqCount += (freq[v] & 1) ? 1 : -1;
      if (freq[v] == 0) distinctCount--;
    };

    vector<bool> ans(q);
    int curL = 0, curR = -1;
    for (int qi : order) {
      int l = queries[qi][0], r = queries[qi][1];
      while (curR < r) add(++curR);
      while (curL > l) add(--curL);
      while (curR > r) remove(curR--);
      while (curL < l) remove(curL++);
      ans[qi] = oddFreqCount == 0 && distinctCount == k;
    }
    return ans;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/516/tests/Q4", "Weekly Contest 516 - Q4",
      [](istream& in) -> tuple<vector<int>, int, vector<vector<int>>> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        auto queries = Parse::int2DVecBracketed(in);
        return {nums, k, queries};
      },
      Parse::boolVecBracketed,  // output: [true,false,...]
      [](auto t) {
        auto [nums, k, queries] = t;
        return Solution().validSubarrays(nums, k, queries);
      });
}
