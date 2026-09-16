#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  string interpret(string command) {
<<<<<<< Updated upstream
    string ans;

    int i = 0;
    while (i < command.length()) {
      if (command[i] == 'G') {
        ans.push_back('G');
        i++;
        continue;
      }

      if (command[i] == '(' && command[i + 1] == ')') {
        ans.push_back('o');
        i += 2;
        continue;
      }

      if (command[i] == '(' && command[i + 1] == 'a') {
        ans.push_back('a');
        ans.push_back('l');
        i += 4;
        continue;
      }

      i++;
    }

    return ans;
=======
    // TODO: implement
    abort();
>>>>>>> Stashed changes
  }
};
