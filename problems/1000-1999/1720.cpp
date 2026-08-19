#include <vector>

#include "runner.h"

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

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1720", "Decode XORed Array",
      [](istream& in) -> pair<vector<int>, int> {
        auto encoded = Parse::intVecBracketed(in);
        int first = 0;
        in >> first;
        return {encoded, first};
      },
      Parse::intVecBracketed,  // output: [1,0,2,1]
      [](auto p) { return Solution().decode(p.first, p.second); });
}
