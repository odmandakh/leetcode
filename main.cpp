// ─────────────────────────────────────────────────────────────────────────────
//  To switch problems: change #include and the 3 lines inside runTests().
//  Parsers available in Parse::  →  intVec, int2DVec, boolVec, strVec
// ─────────────────────────────────────────────────────────────────────────────
#include "runner.h"
// #include "problems/3161_Block_Placement_Queries.cpp"
#include "problems/66_Plus_One.cpp"



int main() {
    runTests(
        std::string(PROJECT_ROOT) + "/tests/66",
        "Problem 66 · Plus One",
        Parse::intVec,                                     // ← pick parser
        Parse::intVec,                                     // ← pick parser
        [](auto d) { return Solution().plusOne(d); }       // ← one line solve
    );
    // runTests(
    //     std::string(PROJECT_ROOT) + "/tests/3161",
    //     "Problem 3161 · Block Placement Queries",
    //     Parse::int2DVec,                                        // input parser
    //     Parse::boolVec,                                         // output parser
    //     [](auto q) { return Solution().getResults(q); }         // solve
    // );
    return 0;
}
