#include "runner.h"
#include "problems/2000-2999/2011.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/2000-2999/2011", "Final Value of Variable After Performing Operations",
      [](istream& in) -> vector<string> {
        string line;
        while (getline(in, line)) {
          if (!line.empty()) break;
        }
        for (char& c : line) {
          if (c == '[' || c == ']' || c == '"' || c == ',') c = ' ';
        }
        istringstream iss(line);
        vector<string> ops;
        string tok;
        while (iss >> tok) ops.push_back(tok);
        return ops;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().finalValueAfterOperations(d)}; });
}
