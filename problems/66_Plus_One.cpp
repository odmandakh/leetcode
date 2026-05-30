#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;  // carry
        }
        // All digits were 9 → prepend 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};


