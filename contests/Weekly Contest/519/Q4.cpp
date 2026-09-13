#include <vector>

using namespace std;

class Solution {
 public:
  long long shadowPairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> val;
    vector<long long> cnt;
    vector<long long> prefix;
    long long ans = 0;

    for (int j = 0; j < n; ++j) {
      int v = nums[j];

      while (!val.empty() && val.back() > v) {
        val.pop_back();
        cnt.pop_back();
        prefix.pop_back();
      }

      long long total = prefix.empty() ? 0 : prefix.back();
      long long sumLess = total;
      if (!val.empty() && val.back() == v) sumLess -= cnt.back();
      ans += sumLess;

      if (!val.empty() && val.back() == v) {
        cnt.back() += 1;
        prefix.back() += 1;
      } else {
        val.push_back(v);
        cnt.push_back(1);
        prefix.push_back(total + 1);
      }
    }

    return ans;
  }
};
