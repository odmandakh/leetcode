#include <array>
#include <vector>

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
// (the previous O(n)-per-query approach was correctness-fixed but TLE'd at
// scale; this replaces it with a segment tree).
class Solution {
  int n, k;
  vector<int> treeProd;                     // product mod k of each node's range
  vector<array<array<int, 5>, 5>> treeCnt;  // treeCnt[node][carry][remainder] = count
  int carryAfter;  // side-output from query(): product mod k after the queried range

  void build(vector<int>& nums, int node, int l, int r) {
    if (l == r) {
      setLeaf(node, nums[l]);
      return;
    }
    int mid = (l + r) / 2;
    build(nums, 2 * node, l, mid);
    build(nums, 2 * node + 1, mid + 1, r);
    pull(node);
  }

  void setLeaf(int node, int val) {
    int vm = val % k;
    treeProd[node] = vm;
    for (int c = 0; c < k; ++c)
      for (int r = 0; r < k; ++r) treeCnt[node][c][r] = ((c * vm) % k == r) ? 1 : 0;
  }

  void pull(int node) {
    int L = 2 * node, R = 2 * node + 1;
    treeProd[node] = (treeProd[L] * treeProd[R]) % k;
    for (int c = 0; c < k; ++c) {
      int midCarry = (c * treeProd[L]) % k;
      for (int r = 0; r < k; ++r) treeCnt[node][c][r] = treeCnt[L][c][r] + treeCnt[R][midCarry][r];
    }
  }

  void update(int node, int l, int r, int pos, int val) {
    if (l == r) {
      setLeaf(node, val);
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(2 * node, l, mid, pos, val);
    else update(2 * node + 1, mid + 1, r, pos, val);
    pull(node);
  }

  // Count of prefix-endpoints within [ql,qr] hitting remainder x, given the
  // product of everything before this query (mod k) is `carry`.
  int query(int node, int l, int r, int ql, int qr, int carry, int x) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) {
      int res = treeCnt[node][carry][x];
      carryAfter = (carry * treeProd[node]) % k;
      return res;
    }
    int mid = (l + r) / 2;
    int leftCount = 0;
    int carryIn = carry;
    if (ql <= mid) {
      leftCount = query(2 * node, l, mid, ql, qr, carryIn, x);
      carryIn = carryAfter;
    }
    int rightCount = 0;
    if (qr > mid) {
      rightCount = query(2 * node + 1, mid + 1, r, ql, qr, carryIn, x);
    } else {
      carryAfter = carryIn;
    }
    return leftCount + rightCount;
  }

 public:
  vector<int> resultArray(vector<int>& nums, int kk, vector<vector<int>>& queries) {
    n = nums.size();
    k = kk;
    treeProd.assign(4 * n, 1);
    treeCnt.assign(4 * n, {});
    build(nums, 1, 0, n - 1);

    vector<int> result;
    result.reserve(queries.size());
    for (auto& q : queries) {
      int index = q[0], value = q[1], start = q[2], x = q[3];
      nums[index] = value;
      update(1, 0, n - 1, index, value);
      result.push_back(query(1, 0, n - 1, start, n - 1, 1 % k, x));
    }
    return result;
  }
};
