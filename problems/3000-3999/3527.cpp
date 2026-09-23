#include <algorithm>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string findCommonResponse(vector<vector<string>>& responses) {
    unordered_map<string, int> count;
    for (auto& response : responses) {
      sort(response.begin(), response.end());
      response.erase(unique(response.begin(), response.end()), response.end());
      for (auto& ans : response) {
        count[ans]++;
      }
    }

    string result = "";
    int maxFreq = 0;
    for (auto& [word, freq] : count) {
      if (freq > maxFreq || (freq == maxFreq && word < result)) {
        maxFreq = freq;
        result = word;
      }
    }
    return result;
  }
};
