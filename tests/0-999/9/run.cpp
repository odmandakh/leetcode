#include "runner.h"
#include "problems/0-999/9.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/9",
      "Palindrome Number",
      [](istream& in) -> int {
        int n = 0;
        in >> n;
        return n;
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto n) { return vector<bool>{Solution().isPalindrome(n)}; }
  );
}
