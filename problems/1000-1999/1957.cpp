#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  string makeFancyString(string s) {
    if (s.length() < 3) return s;  // If string length < 3, it's already fancy

    string result;
    result.push_back(s[0]);  // Add first character
    int count = 1;           // Count of consecutive identical characters

    for (int i = 1; i < s.length(); i++) {
      if (s[i] == result.back()) {
        // Current character matches the last added character
        if (count < 2) {
          result.push_back(s[i]);  // Add if we have less than 2 consecutive
          count++;
        }
        // Skip if count >= 2 (would be third consecutive)
      } else {
        // Different character, reset count and add to result
        result.push_back(s[i]);
        count = 1;
      }
    }

    return result;
  }
};
