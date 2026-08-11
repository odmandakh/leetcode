#include "runner.h"
#include <string>

using namespace std;

class Solution {
public:
  string smallestNumber(string num, long long t) {}
};

inline void run() {
  runTests(
      std::string(PROJECT_ROOT) + "/tests/3348",
      "Smallest Divisible Digit Product II",
      [](std::istream &in) -> std::pair<std::string, long long> {
        std::string num;
        long long t;
        in >> num >> t;
        return {num, t};
      },
      Parse::strVec,
      [](auto p) {
        return std::vector<std::string>{
            Solution().smallestNumber(p.first, p.second)};
      });
}
