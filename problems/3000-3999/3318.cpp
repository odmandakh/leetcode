#include <tuple>
#include <vector>


using namespace std;

// ASSISTED: AI provided the sliding-window + sort-by-(count,value) solution logic directly.
class Solution {
 public:
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> freq(51, 0);
    vector<int> ans(n - k + 1);

    auto computeXSum = [&]() {
      vector<pair<int, int>> counts;  // {count, value}
      for (int v = 1; v <= 50; ++v) {
        if (freq[v] > 0) counts.push_back({freq[v], v});
      }
      sort(counts.rbegin(), counts.rend());  // descending count, ties broken by higher value

      int sum = 0;
      for (int i = 0; i < min((int)counts.size(), x); ++i) {
        sum += counts[i].first * counts[i].second;
      }
      return sum;
    };

    for (int i = 0; i < k; ++i) {
      freq[nums[i]]++;
    }
    ans[0] = computeXSum();

    for (int i = k; i < n; ++i) {
      freq[nums[i - k]]--;  // remove the element leaving the window
      freq[nums[i]]++;      // add the element entering the window
      ans[i - k + 1] = computeXSum();
    }

    return ans;
  }
};

