#include <optional>
#include <vector>


using namespace std;

class Solution {
 public:
  string a = "";
  vector<int> alph;
  Solution() : alph(26, 0) {}

  optional<int> backtrace(string s, string target, int index) {
    for (int i = index; i >= 0; --i) {
      bool flag = false;
      for (char c = target[i] + 1; c <= 'z'; ++c) {
        if (alph[c - 'a']) {
          a.push_back(c);
          alph[c - 'a']--;
          flag = true;
          break;
        }
      }

      if (flag) {
        return i;
      }

      if (i == 0) break;
      alph[a.back() - 'a']++;
      a.pop_back();
    }

    return nullopt;
  }

  string lexGreaterPermutation(string s, string target) {
    for (char ch : s) {
      alph[ch - 'a']++;
    }

    optional<int> index;
    for (int i = 0; i < target.length(); ++i) {
      if (alph[target[i] - 'a']) {
        a.push_back(target[i]);
        alph[target[i] - 'a']--;
        continue;
      }

      index = backtrace(s, target, i);

      if (!index) {
        return (a == target) ? "" : a;
      }
      break;
    }

    if (!index) {
      int lastPos = (int)target.length() - 1;
      alph[a.back() - 'a']++;
      a.pop_back();
      index = backtrace(s, target, lastPos);
      if (!index) return "";
    }

    for (int i = *index + 1; i < target.length(); ++i) {
      for (int j = 0; j < 26; ++j) {
        if (alph[j]) {
          a.push_back(j + 'a');
          alph[j]--;
          break;
        }
      }
    }

    if (a == target) return "";

    return a;
  }
};

