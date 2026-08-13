#include <string>
#include <tuple>
#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: full segment-tree solution written by Claude after direct request,
// not solved independently.
class Solution {
  struct Node {
    int len = 0;
    char leftCh = 0, rightCh = 0;
    int prefLen = 0, sufLen = 0, best = 0;
  };

  vector<Node> tree;
  string str;

  Node merge(const Node& L, const Node& R) {
    Node res;
    res.len = L.len + R.len;
    res.leftCh = L.leftCh;
    res.rightCh = R.rightCh;
    res.best = max(L.best, R.best);
    if (L.rightCh == R.leftCh) {
      res.best = max(res.best, L.sufLen + R.prefLen);
    }
    res.prefLen = (L.prefLen == L.len && L.leftCh == R.leftCh) ? L.len + R.prefLen : L.prefLen;
    res.sufLen = (R.sufLen == R.len && R.rightCh == L.rightCh) ? R.len + L.sufLen : R.sufLen;
    return res;
  }

  void build(int node, int l, int r) {
    if (l == r) {
      tree[node] = {1, str[l], str[l], 1, 1, 1};
      return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }

  void update(int node, int l, int r, int pos, char c) {
    if (l == r) {
      tree[node] = {1, c, c, 1, 1, 1};
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
      update(2 * node, l, mid, pos, c);
    else
      update(2 * node + 1, mid + 1, r, pos, c);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }

 public:
  vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
    str = s;
    int n = (int)s.size();
    tree.assign(4 * n, Node{});
    build(1, 0, n - 1);

    vector<int> ans;
    ans.reserve(queryIndices.size());
    for (int i = 0; i < (int)queryIndices.size(); i++) {
      update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
      ans.push_back(tree[1].best);
    }
    return ans;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2213", "Longest Substring of One Repeating Character",
      [](istream& in) -> tuple<string, string, vector<int>> {
        auto stripQuotes = [](string s) {
          if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
          return s;
        };
        string s, qc;
        in >> s >> qc;
        s = stripQuotes(s);
        qc = stripQuotes(qc);
        auto indices = Parse::intVecBracketed(in);
        return {s, qc, indices};
      },
      Parse::intVecBracketed,  // output: [3,3,4]
      [](auto t) {
        auto [s, qc, idx] = t;
        return Solution().longestRepeating(s, qc, idx);
      });
}
