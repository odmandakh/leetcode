#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string mapWordWeights(vector<string>& words, vector<int>& weights) {
    string result;
    for (const auto& word : words) {
      int weight = 0;
      for (char c : word) {
        weight += weights[c - 'a'];
        weight %= 26;
      }
      result += char('z' - weight);
    }
    return result;
  }
};
