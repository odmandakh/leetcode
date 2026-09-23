#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    unordered_map<int, long long> count;
    count[0] = 1;

    int cur = 0;
    long long ans = 0;

    for (int num : nums) {
      if (num % modulo == k) {
        cur++;
      }
      int need = (cur - k + modulo) % modulo;
      if (count.count(need)) {
        ans += count[need];
      }
      count[cur % modulo]++;
    }

    return ans;
  }
};
