#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, long long> freq;
    long long total_pairs = 0;
    long long result = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
      total_pairs += freq[nums[right]];
      freq[nums[right]]++;

      while (total_pairs >= k) {
        result += (n - right);
        freq[nums[left]]--;
        total_pairs -= freq[nums[left]];
        left++;
      }
    }

    return result;
  }
};
