#include <queue>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node (LeetCode's standard interface --
// raw pointers are required here since averageOfSubtree(TreeNode*) must match
// the exact signature LeetCode expects; no smart-pointer alternative).
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ASSISTED: AI provided the postorder sum/size accumulation solution logic directly.
class Solution {
 public:
  int averageOfSubtree(TreeNode* root) {
    int count = 0;
    dfs(root, count);
    return count;
  }

 private:
  // Returns {sum, size} of the subtree rooted at node, tallying matches into count.
  pair<int, int> dfs(TreeNode* node, int& count) {
    if (node == nullptr) return {0, 0};
    auto [leftSum, leftSize] = dfs(node->left, count);
    auto [rightSum, rightSize] = dfs(node->right, count);
    int sum = leftSum + rightSum + node->val;
    int size = leftSize + rightSize + 1;
    if (node->val == sum / size) ++count;
    return {sum, size};
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
