#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    string stack = "";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        stack += s[i];
      } else {
        if (stack.empty()) return false;
        char top = stack.back();

        if ((s[i] == ')' && top != '(') || (s[i] == ']' && top != '[') ||
            (s[i] == '}' && top != '{'))
          return false;

        stack.pop_back();
      }
    }

    if (stack.empty())
      return true;
    else
      return false;
  }
};
