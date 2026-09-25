#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// ASSISTED: recursive-descent parser written by Claude after direct request ("solve this problem")
class Solution {
 public:
  vector<string> braceExpansionII(string expression) {
    s = expression;
    pos = 0;
    set<string> words = parseUnion();
    return vector<string>(words.begin(), words.end());
  }

 private:
  string s;
  size_t pos = 0;

  // union := concat (',' concat)*
  set<string> parseUnion() {
    set<string> result = parseConcat();
    while (pos < s.size() && s[pos] == ',') {
      ++pos;
      set<string> next = parseConcat();
      result.insert(next.begin(), next.end());
    }
    return result;
  }

  // concat := term+   (stops at ',' or '}' or end)
  set<string> parseConcat() {
    set<string> result = {""};
    while (pos < s.size() && s[pos] != ',' && s[pos] != '}') {
      set<string> term = parseTerm();
      set<string> product;
      for (const string& a : result) {
        for (const string& b : term) product.insert(a + b);
      }
      result = std::move(product);
    }
    return result;
  }

  // term := letter | '{' union '}'
  set<string> parseTerm() {
    if (s[pos] == '{') {
      ++pos;  // '{'
      set<string> inner = parseUnion();
      ++pos;  // '}'
      return inner;
    }
    return {string(1, s[pos++])};
  }
};
