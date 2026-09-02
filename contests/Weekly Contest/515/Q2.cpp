#include <tuple>
#include <vector>


using namespace std;

class Solution {
 public:
  int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
    int max = 0;
    for (int i = 0; i < lights.size(); ++i) {
      if (max < lights[i]) max = lights[i];
    }

    int penalty = 0;
    for (int arrival : arrivalTime) {
      arrival %= period;
      if (arrival >= max) {
        if (penalty < period - arrival) penalty = period - arrival;
      }
    }

    return penalty;
  }
};

