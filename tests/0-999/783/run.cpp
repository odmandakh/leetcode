#include "runner.h"
#include "problems/0-999/783.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/0-999/783", "Minimum Distance Between BST Nodes",
      [](istream& in) -> TreeNode* {
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
        return buildTree(tokens);
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto root) { return vector<int>{Solution().minDiffInBST(root)}; });
}
