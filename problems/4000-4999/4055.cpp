#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
  struct SegBeats {
    int n;
    vector<long long> mx1, mx2, lazy;
    vector<int> cnt1;
    const long long INACTIVE = LLONG_MIN / 2;
    const long long NOLAZY = LLONG_MAX;

    SegBeats(int n_) : n(n_) {
      mx1.assign(4 * n, INACTIVE);
      mx2.assign(4 * n, INACTIVE);
      cnt1.assign(4 * n, 1);
      lazy.assign(4 * n, NOLAZY);
    }
    void pull(int node) {
      int L = 2 * node, R = 2 * node + 1;
      if (mx1[L] == mx1[R]) {
        mx1[node] = mx1[L];
        cnt1[node] = cnt1[L] + cnt1[R];
        mx2[node] = max(mx2[L], mx2[R]);
      } else if (mx1[L] > mx1[R]) {
        mx1[node] = mx1[L];
        cnt1[node] = cnt1[L];
        mx2[node] = max(mx2[L], mx1[R]);
      } else {
        mx1[node] = mx1[R];
        cnt1[node] = cnt1[R];
        mx2[node] = max(mx1[L], mx2[R]);
      }
    }
    void applyTag(int node, long long v) {
      if (v >= mx1[node]) return;
      mx1[node] = v;
      lazy[node] = (lazy[node] == NOLAZY) ? v : min(lazy[node], v);
    }
    void push(int node) {
      if (lazy[node] == NOLAZY) return;
      applyTag(2 * node, lazy[node]);
      applyTag(2 * node + 1, lazy[node]);
      lazy[node] = NOLAZY;
    }
    void pointAssign(int node, int l, int r, int pos, long long val) {
      if (l == r) {
        mx1[node] = val;
        mx2[node] = INACTIVE;
        cnt1[node] = 1;
        lazy[node] = NOLAZY;
        return;
      }
      push(node);
      int mid = (l + r) / 2;
      if (pos <= mid)
        pointAssign(2 * node, l, mid, pos, val);
      else
        pointAssign(2 * node + 1, mid + 1, r, pos, val);
      pull(node);
    }
    void rangeChmin(int node, int l, int r, int ql, int qr, long long v) {
      if (qr < l || r < ql || v >= mx1[node]) return;
      if (ql <= l && r <= qr && mx2[node] < v) {
        applyTag(node, v);
        return;
      }
      push(node);
      int mid = (l + r) / 2;
      rangeChmin(2 * node, l, mid, ql, qr, v);
      rangeChmin(2 * node + 1, mid + 1, r, ql, qr, v);
      pull(node);
    }
    int rangeCountGE(int node, int l, int r, int ql, int qr, long long v) {
      if (qr < l || r < ql || mx1[node] < v) return 0;
      if (ql <= l && r <= qr && mx2[node] < v) return cnt1[node];
      push(node);
      int mid = (l + r) / 2;
      return rangeCountGE(2 * node, l, mid, ql, qr, v) +
             rangeCountGE(2 * node + 1, mid + 1, r, ql, qr, v);
    }
    void pointAssign(int pos, long long val) { pointAssign(1, 0, n - 1, pos, val); }
    void rangeChmin(int ql, int qr, long long v) {
      if (ql <= qr) rangeChmin(1, 0, n - 1, ql, qr, v);
    }
    int rangeCountGE(int ql, int qr, long long v) {
      return (ql <= qr) ? rangeCountGE(1, 0, n - 1, ql, qr, v) : 0;
    }
  };

 public:
  int shadowPairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> order(n);
    for (int i = 0; i < n; ++i) order[i] = i;
    sort(order.begin(), order.end(), [&](int a, int b) {
      if (nums[a] != nums[b]) return nums[a] < nums[b];
      return a < b;
    });
    vector<int> rank(n);
    for (int k = 0; k < n; ++k) rank[order[k]] = k;

    vector<int> sortedVals(n);
    for (int k = 0; k < n; ++k) sortedVals[k] = nums[order[k]];

    SegBeats seg(n);
    long long ans = 0;
    for (int j = 0; j < n; ++j) {
      long long v = nums[j];
      int B = (int)(lower_bound(sortedVals.begin(), sortedVals.end(), v) - sortedVals.begin());
      if (B > 0) {
        ans += seg.rangeCountGE(0, B - 1, v);
        seg.rangeChmin(0, B - 1, v);
      }
      seg.pointAssign(rank[j], LLONG_MAX);
    }
    return (int)ans;
  }
};
