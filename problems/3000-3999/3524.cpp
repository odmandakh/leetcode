#include <vector>

using namespace std;

class Solution {
 public:
  vector<long long> resultArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> result(k, 0);
    vector<int> modCount(k);
    for (int i = 0; i < n; ++i) {
      vector<int> nextModCount(k);
      int mod = nums[i] % k;
      nextModCount[mod]++;

      for (int j = 0; j < k; ++j) {
        int newMod = (j * mod) % k;
        nextModCount[newMod] += modCount[j];
      }

      for (int j = 0; j < k; ++j) {
        result[j] += nextModCount[j];
        modCount[j] = nextModCount[j];
      }
    }

    return result;
  }
};
