#include <vector>


using namespace std;

class Solution {
 public:
  vector<int> decode(vector<int>& encoded, int first) {
    vector<int> result = {first};
    for (int i = 0; i < encoded.size(); ++i) {
      result.push_back(result.back() ^ encoded[i]);
    }
    return result;
  }
};

