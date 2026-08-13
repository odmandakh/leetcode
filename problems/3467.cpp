#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> transformArray(vector<int>& nums) {
    int evenCount = 0;
    for (int num : nums) {
      if (num % 2 == 0) {
        evenCount++;
      }
    }

    vector<int> result = vector<int>(evenCount, 0);
    result.insert(result.end(), nums.size() - evenCount, 1);

    return result;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3467", "Transform Array by Parity",
           Parse::intVecBracketed,                              // TODO: pick parser
           Parse::intVecBracketed,                              // TODO: pick parser
           [](auto d) { return Solution().transformArray(d); }  // TODO: solve
  );
}
