#include "runner.h"
#include "problems/3000-3999/3527.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3527", "Find the Most Common Response",
      [](istream& in) -> vector<vector<string>> {
        // Nested bracket format of quoted strings on one line:
        // [["a","b"],["c"]] -> vector<vector<string>>
        string content, line;
        while (getline(in, line)) {
          if (!line.empty()) {
            content = line;
            break;
          }
        }

        vector<vector<string>> res;
        vector<string> row;
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
            char quote = c;
            size_t j = content.find(quote, i + 1);
            row.push_back(content.substr(i + 1, j - i - 1));
            i = j + 1;
          } else {
            ++i;  // comma or other separator
          }
        }
        return res;
      },
      [](istream& in) -> vector<string> { return {Parse::quotedLine(in)}; },
      [](auto responses) { return vector<string>{Solution().findCommonResponse(responses)}; });
}
