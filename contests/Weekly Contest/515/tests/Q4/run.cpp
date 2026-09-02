#include "runner.h"
#include "contests/Weekly Contest/515/Q4.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/contests/Weekly Contest/515/tests/Q4", "Weekly Contest 515 - Q4",
      [](istream& in) -> tuple<int, int, vector<vector<int>>> {
        int n = 0, start = 0;
        in >> n >> start;
        auto requests = Parse::int2DVecBracketed(in);
        return {n, start, requests};
      },
      [](istream& in) -> vector<long long> {
        long long x;
        vector<long long> v;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto t) {
        auto [n, start, requests] = t;
        return vector<long long>{Solution().elevatorRequests(n, start, requests)};
      });
}
