#include <vector>


using namespace std;

class Solution {
 public:
  string decodeMessage(string key, string message) {
    unordered_map<char, char> substitutionTable;
    int alphabetAscii = 0;
    for (char ch : key) {
      if (ch < 'a' || ch > 'z') continue;

      bool seen = false;
      for (auto [k, v] : substitutionTable) {
        if (k == ch) {
          seen = true;
          break;
        }
      }

      if (!seen) {
        substitutionTable[ch] = 'a' + alphabetAscii;
        alphabetAscii++;
      }
    }

    for (char& ch : message) {
      if (ch < 'a' || ch > 'z') continue;

      for (auto [k, v] : substitutionTable) {
        if (k == ch) {
          ch = v;
          break;
        }
      }
    }

    return message;
  }
};

