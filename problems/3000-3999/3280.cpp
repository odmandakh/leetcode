#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  string convertDateToBinary(string date) {
    int number = 0;
    string result;
    for (char c : date) {
      if (c == '-') {
        result += toBinary(number);
        number = 0;
        result += '-';
      } else {
        number = number * 10 + (c - '0');
      }
    }

    result += toBinary(number);
    return result;
  }

  string toBinary(int n) {
    if (n == 0) return "0";

    string result;
    while (n > 0) {
      result += char('0' + (n & 1));
      n >>= 1;
    }
    ranges::reverse(result);

    return result;
  }
};

