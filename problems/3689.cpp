//
// Created by Odmandakh Battulga on 2026.06.09.
//

#include <vector>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max = nums[0];
        long long min = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > max) max = nums[i];
            if (nums[i] < min) min = nums[i];
        }

        return (max - min) * k;
    }
};