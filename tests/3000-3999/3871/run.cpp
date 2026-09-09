#include "runner.h"
#include "problems/3000-3999/3871.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3871",
      "Count Commas in Range II",
      [](istream& in) -> long long {
        long long n = 0;
        in >> n;
        return n;
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto n) { return vector<long long>{Solution().countCommas(n)}; }
  );
}
