#include <string>
#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    int count = 0;
    for (char stone : stones) {
      if (jewels.find(stone) != string::npos) {
        count++;
      }
    }
    return count;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/0-999/771", "Jewels and Stones",
           [](istream& in) -> pair<string, string> {
             auto stripQuotes = [](string s) {
               if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
               return s;
             };
             string jewels, stones;
             in >> jewels >> stones;
             return {stripQuotes(jewels), stripQuotes(stones)};
           },
           Parse::intVec,  // output: single int (as a 1-element vector)
           [](auto p) { return vector<int>{Solution().numJewelsInStones(p.first, p.second)}; }
  );
}
