#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> arr;
    int i = 0;
    for (string word : words) {
      if (word.find(x) != string::npos) arr.push_back(i);

      i++;
    }

    return arr;
  }
};
