#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  vector<int> getConcatenation(vector<int>& nums) {
    vector<int> result = nums;
    for (int num : nums) {
      result.push_back(num);
    }
    return result;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/1000-1999/1929", "Concatenation of Array",
           Parse::intVecBracketed,                                // TODO: pick parser
           Parse::intVecBracketed,                                // TODO: pick parser
           [](auto d) { return Solution().getConcatenation(d); }  // TODO: solve
  );
}
