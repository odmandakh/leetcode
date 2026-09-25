#include <algorithm>
#include <array>
#include <string>
#include <vector>

using namespace std;

// ASSISTED: full greedy solution written by Claude after direct request ("solve this problem")
class Solution {
 public:
  string smallestNumber(string num, long long t) {
    // t must factor entirely into the primes a digit can contribute: 2, 3, 5, 7.
    array<int, 4> need{};
    for (int p = 0; p < 4; ++p) {
      while (t % kPrimes[p] == 0) {
        t /= kPrimes[p];
        ++need[p];
      }
    }
    if (t != 1) return "-1";

    int n = num.size();
    int firstZero = num.find('0') == string::npos ? n : num.find('0');

    // have[i] = prime exponents of the product of num[0..i-1] (valid while i <= firstZero).
    vector<array<int, 4>> have(firstZero + 1);
    for (int i = 0; i < firstZero; ++i) {
      have[i + 1] = have[i];
      for (int p = 0; p < 4; ++p) have[i + 1][p] += kExp[num[i] - '0'][p];
    }

    if (firstZero == n && minDigits(remaining(need, have[n])) == 0) return num;

    // Keep prefix num[0..i-1], bump position i to d > num[i], fill the rest minimally.
    // Rightmost i and smallest d first gives the smallest valid number of length n.
    for (int i = min(firstZero, n - 1); i >= 0; --i) {
      for (int d = num[i] - '0' + 1; d <= 9; ++d) {
        array<int, 4> cur = have[i];
        for (int p = 0; p < 4; ++p) cur[p] += kExp[d][p];
        array<int, 4> rest = remaining(need, cur);
        int suffixLen = n - 1 - i;
        if (minDigits(rest) <= suffixLen) {
          return num.substr(0, i) + char('0' + d) + buildSuffix(rest, suffixLen);
        }
      }
    }

    // No n-digit answer: go longer, padding with leading 1s.
    int k = minDigits(need);
    return buildSuffix(need, max(n + 1, k));
  }

 private:
  static constexpr int kPrimes[4] = {2, 3, 5, 7};
  // Exponents of 2, 3, 5, 7 in each digit 0..9.
  static constexpr int kExp[10][4] = {
      {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {2, 0, 0, 0},
      {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}, {3, 0, 0, 0}, {0, 2, 0, 0},
  };

  static array<int, 4> remaining(const array<int, 4>& need, const array<int, 4>& got) {
    array<int, 4> r{};
    for (int p = 0; p < 4; ++p) r[p] = max(0, need[p] - got[p]);
    return r;
  }

  // Greedy packing: 7s, 5s, 9 = 3^2, 8 = 2^3, then combine leftovers
  // (3^0..1, 2^0..2) into the fewest / smallest digits.
  static string minDigitsString(const array<int, 4>& r) {
    string s;
    s.append(r[3], '7');
    s.append(r[2], '5');
    s.append(r[1] / 2, '9');
    s.append(r[0] / 3, '8');
    int r3 = r[1] % 2, r2 = r[0] % 3;
    if (r3 == 1 && r2 == 2)
      s += "26";
    else if (r3 == 1 && r2 == 1)
      s += '6';
    else if (r3 == 1)
      s += '3';
    else if (r2 == 2)
      s += '4';
    else if (r2 == 1)
      s += '2';
    sort(s.begin(), s.end());
    return s;
  }

  static int minDigits(const array<int, 4>& r) {
    int r3 = r[1] % 2, r2 = r[0] % 3;
    int extra = (r3 == 1 && r2 == 2) ? 2 : (r3 || r2) ? 1 : 0;
    return r[3] + r[2] + r[1] / 2 + r[0] / 3 + extra;
  }

  static string buildSuffix(const array<int, 4>& r, int len) {
    string core = minDigitsString(r);
    return string(len - core.size(), '1') + core;
  }
};
