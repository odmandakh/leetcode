#include <algorithm>
#include <vector>


using namespace std;

class Solution {
 public:
  vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
    vector<int> result;
    for (int i = 0; i < order.size(); ++i) {
      if (find(friends.begin(), friends.end(), order[i]) != friends.end()) {
        result.push_back(order[i]);
      }
    }
    return result;
  }
};

