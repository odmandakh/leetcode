#include <vector>

#include "runner.h"

using namespace std;

class Solution {
 public:
  int maxFreqSum(string s) {
    unordered_map<char, int> vowelFreq;
    unordered_map<char, int> consonantFreq;

    array vowels = {'a', 'e', 'i', 'o', 'u'};

    for (char alphabet = 'a'; alphabet <= 'z'; ++alphabet) {
      if (find(vowels.begin(), vowels.end(), alphabet) != vowels.end())
        vowelFreq[alphabet] = 0;
      else
        consonantFreq[alphabet] = 0;
    }

    for (char ch : s) {
      if (find(vowels.begin(), vowels.end(), ch) != vowels.end())
        vowelFreq[ch]++;
      else
        consonantFreq[ch]++;
    }

    int maxVowel = 0, maxConsonant = 0;
    for (auto [k, v] : vowelFreq) {
      maxVowel = maxVowel > v ? maxVowel : v;
    }
    for (auto [k, v] : consonantFreq) {
      maxConsonant = maxConsonant > v ? maxConsonant : v;
    }

    return maxVowel + maxConsonant;
  }
};

inline void run() {
  runTests(string(PROJECT_ROOT) + "/tests/3000-3999/3541", "Find Most Frequent Vowel and Consonant",
           Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
           Parse::intVec,        // output: single int (as a 1-element vector)
           [](auto s) { return vector<int>{Solution().maxFreqSum(s)}; });
}
