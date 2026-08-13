#include <string>

#include "runner.h"

using namespace std;

class Solution {
 public:
  string smallestNumber(string num, long long t) { return "asd"; }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3348", "Smallest Divisible Digit Product II",
      [](istream& in) -> pair<string, long long> {
        string num;
        long long t;
        in >> num >> t;
        return {num, t};
      },
      Parse::strVec,
      [](auto p) { return vector<string>{Solution().smallestNumber(p.first, p.second)}; });
}
