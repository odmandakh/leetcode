#include "runner.h"
#include "problems/0-999/951.cpp"

inline vector<string> readTreeTokens(istream& in) {
  string line;
  while (getline(in, line)) {
    if (!line.empty()) break;
  }
  for (char& c : line) {
    if (c == '[' || c == ']' || c == ',') c = ' ';
  }
  istringstream iss(line);
  vector<string> tokens;
  string tok;
  while (iss >> tok) tokens.push_back(tok);
  return tokens;
}

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/951",
      "Flip Equivalent Binary Trees",
      [](istream& in) -> pair<TreeNode*, TreeNode*> {
        TreeNode* t1 = buildTree(readTreeTokens(in));
        TreeNode* t2 = buildTree(readTreeTokens(in));
        return {t1, t2};
      },
      Parse::boolVec,  // output: single bool (as a 1-element vector), true/false
      [](auto p) { return vector<bool>{Solution().flipEquiv(p.first, p.second)}; }
  );
}
