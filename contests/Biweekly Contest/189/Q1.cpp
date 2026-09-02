#include <vector>


using namespace std;

class Solution {
 public:
  int elevatorRequests(int n, vector<int>& requests) {
    long ans = requests[0];
    for (int i = 1; i < requests.size(); ++i) {
      ans += abs(requests[i] - requests[i - 1]);
    }

    return ans;
  }
};

