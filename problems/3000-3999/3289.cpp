#include <vector>


using namespace std;

class Solution {
 public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    vector<int> freq(nums.size() - 2, 0);
    vector<int> result;
    for (int num : nums) {
      freq[num]++;
      if (freq[num] == 2) {
        result.push_back(num);
      }
    }
    return result;
  }
};

