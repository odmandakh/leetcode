#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    int max = 0;

    for (int i = 0; i < candies.size(); ++i) {
      max = candies[i] > max ? candies[i] : max;
    }

    for (int i = 0; i < candies.size(); ++i) {
      if (max > candies[i] + extraCandies) {
        ans.push_back(false);
      } else {
        ans.push_back(true);
      }
    }

    return ans;
  }
};
