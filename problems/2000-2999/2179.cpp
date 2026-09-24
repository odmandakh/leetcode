#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      pos[nums1[i]] = i;  // Map positions of nums1
    }

    vector<int> mappedNums2(n);
    for (int i = 0; i < n; ++i) {
      mappedNums2[i] = pos[nums2[i]];  // Transform nums2 into indices based on nums1
    }

    // Fenwick Tree for counting
    vector<int> fenwick(n + 1, 0);

    auto update = [&](int index, int value) {
      while (index <= n) {
        fenwick[index] += value;
        index += index & -index;
      }
    };

    auto query = [&](int index) {
      int sum = 0;
      while (index > 0) {
        sum += fenwick[index];
        index -= index & -index;
      }
      return sum;
    };

    // Count left and right contributions
    vector<long long> leftCount(n, 0), rightCount(n, 0);

    // Count left contributions
    for (int i = 0; i < n; ++i) {
      leftCount[i] = query(mappedNums2[i]);
      update(mappedNums2[i] + 1, 1);
    }

    // Reset Fenwick Tree
    fill(fenwick.begin(), fenwick.end(), 0);

    // Count right contributions
    for (int i = n - 1; i >= 0; --i) {
      rightCount[i] = query(n) - query(mappedNums2[i]);
      update(mappedNums2[i] + 1, 1);
    }

    // Calculate total good triplets
    long long result = 0;
    for (int i = 0; i < n; ++i) {
      result += leftCount[i] * rightCount[i];
    }

    return result;
  }
};
