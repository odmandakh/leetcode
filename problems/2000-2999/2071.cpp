#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    multiset<int> available(workers.end() - k, workers.end());  // take the strongest k workers
    int used_pills = 0;

    for (int i = k - 1; i >= 0; --i) {
      int t = tasks[i];
      auto it = available.lower_bound(t);
      if (it != available.end()) {
        // Worker strong enough without pill
        available.erase(it);
      } else {
        // Try with pill
        if (used_pills == pills) return false;
        it = available.lower_bound(t - strength);
        if (it == available.end()) return false;
        available.erase(it);
        used_pills++;
      }
    }
    return true;
  }

  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int low = 0, high = min((int)tasks.size(), (int)workers.size());
    int ans = 0;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (canAssign(mid, tasks, workers, pills, strength)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return ans;
  }
};
