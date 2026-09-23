#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  long long calculateScore(vector<string>& instructions, vector<int>& values) {
    long long score = 0;
    int i = 0, n = instructions.size();
    while (i < n && i >= 0) {
      if (instructions[i] == "used") break;
      if (instructions[i] == "add") {
        score += values[i];
        instructions[i] = "used";
        i++;
        continue;
      }
      if (instructions[i] == "jump") {
        instructions[i] = "used";
        i += values[i];
        continue;
      }
    }

    return score;
  }
};
