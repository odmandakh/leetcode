#include "runner.h"
#include "problems/3000-3999/3517.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3517", "Smallest Palindromic Rearrangement I",
      Parse::quotedString,
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto s) { return vector<string>{Solution().smallestPalindrome(s)}; });
}
