#include "runner.h"
#include "problems/3000-3999/3212.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3212", "Count Submatrices With Equal Frequency of X and Y",
      [](istream& in) -> vector<vector<char>> {
        // Nested bracket format of single quoted chars on one line:
        // [["X","Y","."],["Y",".","."]] -> vector<vector<char>>
        string content, line;
        while (getline(in, line)) {
          if (!line.empty()) {
            content = line;
            break;
          }
        }

        vector<vector<char>> res;
        vector<char> row;
        int depth = 0;
        for (size_t i = 0; i < content.size();) {
          char c = content[i];
          if (c == '[') {
            ++depth;
            if (depth == 2) row.clear();
            ++i;
          } else if (c == ']') {
            if (depth == 2) res.push_back(row);
            --depth;
            ++i;
          } else if (c == '"' || c == '\'') {
            row.push_back(content[i + 1]);
            i += 3;  // skip opening quote, char, closing quote
          } else {
            ++i;  // comma or other separator
          }
        }
        return res;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto grid) { return vector<int>{Solution().numberOfSubmatrices(grid)}; });
}
