#include <climits>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "runner.h"

using namespace std;

// Definition for a binary tree node (LeetCode's standard interface --
// raw pointers are required here since minDiffInBST(TreeNode*) must match
// the exact signature LeetCode expects; no smart-pointer alternative).
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int minDiffInBST(TreeNode* root) {
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;
    inorder(root, prev, minDiff);
    return minDiff;
  }

  void inorder(TreeNode* node, TreeNode*& prev, int& minDiff) {
    if (node == nullptr) return;
    inorder(node->left, prev, minDiff);
    if (prev != nullptr) {
      minDiff = min(minDiff, node->val - prev->val);
    }
    prev = node;
    inorder(node->right, prev, minDiff);
  }
};

// Builds a tree from LeetCode's level-order array format, e.g.
// [4,2,6,1,3] or [1,0,48,null,null,12,49] -- "null" marks a missing child.
TreeNode* buildTree(const vector<string>& tokens) {
  if (tokens.empty() || tokens[0] == "null") return nullptr;
  TreeNode* root = new TreeNode(stoi(tokens[0]));
  queue<TreeNode*> q;
  q.push(root);
  size_t i = 1;
  while (!q.empty() && i < tokens.size()) {
    TreeNode* node = q.front();
    q.pop();
    if (i < tokens.size()) {
      if (tokens[i] != "null") {
        node->left = new TreeNode(stoi(tokens[i]));
        q.push(node->left);
      }
      ++i;
    }
    if (i < tokens.size()) {
      if (tokens[i] != "null") {
        node->right = new TreeNode(stoi(tokens[i]));
        q.push(node->right);
      }
      ++i;
    }
  }
  return root;
}

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
