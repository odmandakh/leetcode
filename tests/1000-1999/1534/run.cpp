#include "runner.h"
#include "problems/1000-1999/1534.cpp"

struct GoodTripletsArgs {
  vector<int> arr;
  int a, b, c;
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/1000-1999/1534",
      "Count Good Triplets",
      [](istream& in) -> GoodTripletsArgs {
        GoodTripletsArgs args;
        args.arr = Parse::intVecBracketed(in);
        in >> args.a >> args.b >> args.c;
        return args;
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto args) { return vector<int>{Solution().countGoodTriplets(args.arr, args.a, args.b, args.c)}; }
  );
}
