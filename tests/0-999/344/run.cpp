#include "runner.h"
#include "problems/0-999/344.cpp"

inline vector<char> parseCharVecBracketed(istream& in) {
  auto strs = Parse::strVecBracketed(in);
  vector<char> v;
  for (auto& s : strs) v.push_back(s.empty() ? ' ' : s[0]);
  return v;
}

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/344",
      "Reverse String",
      parseCharVecBracketed,  // input: ["h","e","l","l","o"]
      parseCharVecBracketed,  // output: ["o","l","l","e","h"]
      [](auto s) { Solution().reverseString(s); return s; }  // void in-place mutator
  );
}
