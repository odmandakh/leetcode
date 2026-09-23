#include <map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  bool solve(vector<vector<long long>> pre, int n, int m, long long total, bool col,
             map<long long int, pair<long long int, long long int>>& mpp) {
    if (col) {
      for (int i = 0; i < m - 1; i++) {
        long long sum = pre[n - 1][i];
        long long rem = total - sum;

        if (sum == rem) return true;
        if (sum > rem) {
          long long diff = sum - rem;
          if (mpp.find(diff) != mpp.end()) {
            int r = mpp[diff].first, c = mpp[diff].second;
            if (c == 0 || c == i) return true;
          }
        }
        if (rem > sum) {
          long long diff = rem - sum;
          if (mpp.find(diff) != mpp.end()) {
            int r = mpp[diff].first, c = mpp[diff].second;
            if (c == i + 1 || c == m - 1) return true;
          }
        }
      }
      return false;
    } else {
      for (int i = 0; i < n - 1; i++) {
        long long sum = pre[i][m - 1];
        long long rem = total - sum;

        if (sum == rem) return true;
        if (sum > rem) {
          long long diff = sum - rem;
          if (mpp.find(diff) != mpp.end()) {
            int r = mpp[diff].first, c = mpp[diff].second;
            if (r == 0 || r == i) return true;
          }
        }
        if (rem > sum) {
          long long diff = rem - sum;
          if (mpp.find(diff) != mpp.end()) {
            int r = mpp[diff].first, c = mpp[diff].second;
            if (r == i + 1 || r == n - 1) return true;
          }
        }
      }
      return false;
    }
  }

 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    map<long long int, pair<long long int, long long int>> mpp;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mpp[grid[i][j]] = {i, j};
      }
    }

    vector<vector<long long>> prerow(n, vector<long long>(m, 0));
    vector<vector<long long>> precol(n, vector<long long>(m, 0));
    long long curr = 0, total = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        prerow[i][j] = curr + grid[i][j];
        // cout<<prerow[i][j];
        curr = prerow[i][j];
        total += grid[i][j];
      }
    }
    curr = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        precol[j][i] = curr + grid[j][i];
        curr = precol[j][i];
      }
    }
    if (n == 1) return solve(precol, n, m, total, 1, mpp);
    if (m == 1) return solve(prerow, n, m, total, 0, mpp);
    for (int i = 0; i < n; i++) {
      // sum till ith row
      long long sum = prerow[i][m - 1];
      long long rem = total - sum;
      if (sum == rem) return true;
      if (sum > rem) {
        long long diff = sum - rem;
        if (mpp.find(diff) != mpp.end()) {
          //  if(n==1 || m==1) continue;

          int r = mpp[diff].first, c = mpp[diff].second;
          // if(i==0 && (c==0 || c==m-1)) return true;
          if (i == 0 && r <= i && c != 0 && c != m - 1) continue;
          if (r <= i) return true;
        }
      } else if (rem > sum) {
        long long diff = rem - sum;
        if (mpp.find(diff) != mpp.end()) {
          int r = mpp[diff].first, c = mpp[diff].second;
          // if(n==1 || m==1) continue;
          // if(i==n-1 && (c==0 || c==m-1)) return true;
          if (i == n - 2 && r > i && c != 0 && c != m - 1) continue;
          if (r > i) return true;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      // sum till ith row
      long long sum = precol[n - 1][i];
      long long rem = total - sum;
      if (sum == rem) return true;
      if (sum > rem) {
        long long diff = sum - rem;
        if (mpp.find(diff) != mpp.end()) {
          int r = mpp[diff].first, c = mpp[diff].second;
          //  if(n==1 || m==1) continue;
          if (i == 0 && c <= i && r != 0 && r != n - 1) continue;
          if (c <= i) return true;
        }
      } else if (rem > sum) {
        long long diff = rem - sum;
        //   cout<<diff<<endl;
        if (mpp.find(diff) != mpp.end()) {
          int r = mpp[diff].first, c = mpp[diff].second;
          // if(n==1 || m==1) continue;
          if (i == m - 2 && c > i && r != 0 && r != n - 1) continue;
          if (c > i) return true;
        }
      }
    }
    return false;
  }
};
