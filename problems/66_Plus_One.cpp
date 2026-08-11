#include "runner.h"
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

inline void run() {
  runTests(std::string(PROJECT_ROOT) + "/tests/66", "Problem 66 · Plus One",
           Parse::intVec,                               // ← pick parser
           Parse::intVec,                               // ← pick parser
           [](auto d) { return Solution().plusOne(d); } // ← one line solve
  );
}
