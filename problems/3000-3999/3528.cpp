#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
    const int MOD = 1e9 + 7;
    int n = conversions.size() + 1;
    vector<vector<pair<int, int>>> graph(n);

    // Build the graph
    for (auto& conv : conversions) {
      int u = conv[0], v = conv[1], factor = conv[2];
      graph[u].push_back({v, factor});
    }

    vector<int> result(n, 0);
    result[0] = 1;  // 1 unit of type 0

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto& [v, factor] : graph[u]) {
        result[v] = (long long)result[u] * factor % MOD;
        q.push(v);
      }
    }

    return result;
  }
};
