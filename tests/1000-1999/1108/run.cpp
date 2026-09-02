#include "runner.h"
#include "problems/1000-1999/1108.cpp"

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
