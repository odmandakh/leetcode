#include <algorithm>
#include <optional>
#include <string>
#include <vector>


using namespace std;

// ASSISTED: AI provided the half-string reduction + greedy/backtrack solution logic directly.
class Solution {
 public:
  string lexPalindromicPermutation(string s, string target) {
    int n = s.length();
    vector<int> cnt(26, 0);
    for (char ch : s) cnt[ch - 'a']++;

    int oddCount = 0, oddChar = -1;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] % 2 != 0) {
        oddCount++;
        oddChar = i;
      }
    }

    bool oddLen = (n % 2 != 0);
    if (oddLen && oddCount != 1) return "";
    if (!oddLen && oddCount != 0) return "";

    char middle = 0;
    if (oddLen) {
      middle = 'a' + oddChar;
      cnt[oddChar]--;
    }

    vector<int> half(26, 0);
    for (int i = 0; i < 26; ++i) half[i] = cnt[i] / 2;

    int halfLen = n / 2;
    string targetHalf = target.substr(0, halfLen);

    // Try matching target's own first half exactly first -- it's the
    // smallest possible half, so if it works, nothing beats it.
    vector<int> tmp = half;
    bool canExact = true;
    for (char ch : targetHalf) {
      if (tmp[ch - 'a'] > 0) {
        tmp[ch - 'a']--;
      } else {
        canExact = false;
        break;
      }
    }

    if (canExact) {
      string candidate = targetHalf;
      if (oddLen) candidate += middle;
      string rev = targetHalf;
      reverse(rev.begin(), rev.end());
      candidate += rev;
      if (candidate > target) return candidate;
    }

    optional<string> firstHalf = smallestGreaterPermutation(half, targetHalf);
    if (!firstHalf) return "";

    string result = *firstHalf;
    if (oddLen) result += middle;
    string rev = *firstHalf;
    reverse(rev.begin(), rev.end());
    result += rev;
    return result;
  }

 private:
  optional<int> backtrack(vector<int>& pool, const string& target, int index, string& built) {
    for (int i = index; i >= 0; --i) {
      bool found = false;
      for (char c = target[i] + 1; c <= 'z'; ++c) {
        if (pool[c - 'a'] > 0) {
          built.push_back(c);
          pool[c - 'a']--;
          found = true;
          break;
        }
      }
      if (found) return i;
      if (i == 0) break;
      pool[built.back() - 'a']++;
      built.pop_back();
    }
    return nullopt;
  }

  optional<string> smallestGreaterPermutation(vector<int> pool, const string& target) {
    int n = target.length();
    string built;

    optional<int> pivotPos;
    for (int i = 0; i < n; ++i) {
      if (pool[target[i] - 'a'] > 0) {
        built.push_back(target[i]);
        pool[target[i] - 'a']--;
        continue;
      }
      pivotPos = backtrack(pool, target, i, built);
      if (!pivotPos) return nullopt;
      break;
    }

    if (!pivotPos) {
      if (built.empty()) return nullopt;
      pool[built.back() - 'a']++;
      built.pop_back();
      pivotPos = backtrack(pool, target, n - 1, built);
      if (!pivotPos) return nullopt;
    }

    for (int i = *pivotPos + 1; i < n; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (pool[j] > 0) {
          built.push_back('a' + j);
          pool[j]--;
          break;
        }
      }
    }

    return built;
  }
};

