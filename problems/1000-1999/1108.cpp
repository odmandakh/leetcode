#include <string>
#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  string defangIPaddr(string address) {
    string result;
    for (char c : address) {
      if (c == '.')
        result += "[.]";
      else
        result += c;
    }
    return result;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1108", "Defanging an IP Address",
      [](istream& in) -> string {
        string s;
        in >> s;
        return s;
      },
      [](istream& in) -> vector<string> {
        string s;
        in >> s;
        return {s};
      },
      [](auto s) { return vector<string>{Solution().defangIPaddr(s)}; });
}
