#include "runner.h"
#include "problems/3000-3999/3524.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3524", "Find X Value of Array I",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int k = 0;
        in >> k;
        return {nums, k};
      },
      [](istream& in) -> vector<long long> {
        // Bracket/comma format: [9,2,4] -> vector<long long>
        vector<long long> v;
        string line;
        while (getline(in, line)) {
          if (line.empty()) continue;
          for (char& c : line)
            if (c == '[' || c == ']' || c == ',') c = ' ';
          istringstream iss(line);
          long long x;
          while (iss >> x) v.push_back(x);
          if (!v.empty()) break;
        }
        return v;
      },
      [](auto p) { return Solution().resultArray(p.first, p.second); });
}
