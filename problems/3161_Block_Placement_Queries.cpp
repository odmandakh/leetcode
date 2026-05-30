#include <algorithm>
#include <vector>

class Solution {
    static const int MAXN = 50002;

    struct Node {
        int max_gap   = 0;   // max gap between any two consecutive obstacles
        int left_obs  = -1;  // leftmost obstacle in this range (-1 = none)
        int right_obs = -1;  // rightmost obstacle in this range (-1 = none)
    };

    std::vector<Node> tree;

    Node merge(const Node& L, const Node& R) {
        Node res;
        res.max_gap = std::max(L.max_gap, R.max_gap);
        // Gap bridging the two children
        if (L.right_obs != -1 && R.left_obs != -1)
            res.max_gap = std::max(res.max_gap, R.left_obs - L.right_obs);
        res.left_obs  = (L.left_obs  != -1) ? L.left_obs  : R.left_obs;
        res.right_obs = (R.right_obs != -1) ? R.right_obs : L.right_obs;
        return res;
    }

    void update(int node, int l, int r, int pos) {
        if (l == r) { tree[node] = {0, pos, pos}; return; }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * node,     l,       mid, pos);
        else            update(2 * node + 1, mid + 1, r,   pos);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return {};
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return merge(
            query(2 * node,     l,       mid, ql, qr),
            query(2 * node + 1, mid + 1, r,   ql, qr)
        );
    }

public:
    std::vector<bool> getResults(std::vector<std::vector<int>>& queries) {
        tree.assign(4 * MAXN, Node{});
        // 0 is always an implicit left wall
        update(1, 0, MAXN - 1, 0);

        std::vector<bool> results;

        for (auto& q : queries) {
            if (q[0] == 1) {
                // Type 1: place obstacle at x
                update(1, 0, MAXN - 1, q[1]);
            } else {
                // Type 2: can block of size sz fit in [0, x]?
                int x = q[1], sz = q[2];
                Node res = query(1, 0, MAXN - 1, 0, x);
                // Also check gap from rightmost obstacle to x (x acts as right wall)
                int max_gap = res.max_gap;
                if (res.right_obs != -1)
                    max_gap = std::max(max_gap, x - res.right_obs);
                results.push_back(max_gap >= sz);
            }
        }
        return results;
    }
};

