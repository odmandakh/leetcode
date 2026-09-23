#include <tuple>

#include "runner.h"
#include "problems/4000-4999/4027.cpp"

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/4000-4999/4027", "Elevator Requests III",
      [](istream& in) -> tuple<int, int, vector<vector<int>>> {
        int n = 0, start = 0;
        in >> n >> start;
        auto requests = Parse::int2DVecBracketed(in);
        return {n, start, requests};
      },
      [](istream& in) -> vector<long long> {
        vector<long long> v;
        long long x;
        while (in >> x) v.push_back(x);
        return v;
      },
      [](auto t) {
        auto& [n, start, requests] = t;
        return vector<long long>{Solution().elevatorRequests(n, start, requests)};
      });
}
