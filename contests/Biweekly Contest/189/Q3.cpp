#include <string>
#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: asked for the solution directly instead of solving independently
class Solution {
 public:
  int kthDigit(long long k) {
    static constexpr int kSingleDigitCount = 9;
    if (k <= kSingleDigitCount) return static_cast<int>(k);
    k -= kSingleDigitCount;

    long long d = 2;
    long long blockCountAtLength = 9;
    long long levelStartB = 1;
    while (k > blockCountAtLength * 10 * d) {
      k -= blockCountAtLength * 10 * d;
      levelStartB *= 10;
      blockCountAtLength *= 10;
      ++d;
    }

    const long long blockDigits = 10 * d;
    const long long blockOffset = (k - 1) / blockDigits;
    const long long posWithinBlock = (k - 1) % blockDigits;
    const long long b = levelStartB + blockOffset;

    const long long blockStart = 10 * b;
    const long long blockEnd = blockStart + 9;
    const long long numberOffset = posWithinBlock / d;
    const long long digitOffset = posWithinBlock % d;
    const bool descending = b % 2 == 1;
    const long long number = descending ? blockEnd - numberOffset : blockStart + numberOffset;

    return digitAt(number, digitOffset);
  }

 private:
  static int digitAt(long long number, long long posFromLeft) {
    return to_string(number)[posFromLeft] - '0';
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Biweekly Contest/189/tests/Q3", "Biweekly Contest 189 - Q3",
      [](istream& in) -> long long {
        long long k = 0;
        in >> k;
        return k;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto k) { return vector<int>{Solution().kthDigit(k)}; });
}
