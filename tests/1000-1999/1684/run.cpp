#include "runner.h"
#include "problems/1000-1999/1684.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1684", "Count the Number of Consistent Strings",
      [](istream& in) -> pair<string, vector<string>> {
        string allowed = Parse::quotedString(in);
        string line;
        while (getline(in, line)) {
          if (!line.empty()) break;
        }
        for (char& c : line) {
          if (c == '[' || c == ']' || c == ',' || c == '"') c = ' ';
        }
        istringstream iss(line);
        vector<string> words;
        string tok;
        while (iss >> tok) words.push_back(tok);
        return {allowed, words};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().countConsistentStrings(p.first, p.second)}; });
}
