#include <vector>


using namespace std;

class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int result = 0;
    for (const auto& op : operations) {
      if (op == "X++" || op == "++X") {
        result++;
      } else if (op == "X--" || op == "--X") {
        result--;
      }
    }
    return result;
  }
};

