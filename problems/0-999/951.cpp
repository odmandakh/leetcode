#include <queue>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node (LeetCode's standard interface --
// raw pointers are required here since flipEquiv(TreeNode*, TreeNode*) must
// match the exact signature LeetCode expects; no smart-pointer alternative).
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
      return true;
    }
    if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
      return false;
    }

    TreeNode* child1 = root1->left;
    TreeNode* child2 = root1->right;

    TreeNode* child3 = root2->left;
    TreeNode* child4 = root2->right;

    bool noFlip = flipEquiv(child1, child3) && flipEquiv(child2, child4);
    bool flip = flipEquiv(child1, child4) && flipEquiv(child2, child3);

    return noFlip || flip;
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
