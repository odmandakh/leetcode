#include "runner.h"
#include "problems/3000-3999/3522.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3522", "Calculate Score After Performing Instructions",
      [](istream& in) -> pair<vector<string>, vector<int>> {
        auto instructions = Parse::strVecBracketed(in);
        auto values = Parse::intVecBracketed(in);
        return {instructions, values};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto p) { return vector<long long>{Solution().calculateScore(p.first, p.second)}; });
}
