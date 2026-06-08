// ─────────────────────────────────────────────────────────────────────────────
//  To switch problems: change #include and the 3 lines inside runTests().
//  Parsers available in Parse::  →  intVec, int2DVec, boolVec, strVec
// ─────────────────────────────────────────────────────────────────────────────
#include "runner.h"
// #include "problems/3161_Block_Placement_Queries.cpp"
// #include "problems/66_Plus_One.cpp"
#include "problems/2161.cpp"



int main() {
    // runTests(
    //     std::string(PROJECT_ROOT) + "/tests/66",
    //     "Problem 66 · Plus One",
    //     Parse::intVec,                                     // ← pick parser
    //     Parse::intVec,                                     // ← pick parser
    //     [](auto d) { return Solution().plusOne(d); }       // ← one line solve
    // );
    // runTests(
    //     std::string(PROJECT_ROOT) + "/tests/3161",
    //     "Problem 3161 · Block Placement Queries",
    //     Parse::int2DVec,                                        // input parser
    //     Parse::boolVec,                                         // output parser
    //     [](auto q) { return Solution().getResults(q); }         // solve
    // );
    runTests(
        std::string(PROJECT_ROOT) + "/tests/2161",
        "Problem 2161 · Partition Array According to Given Pivot",
        // parseInput: line 1 = [a,b,c,...], line 2 = pivot
        [](std::istream& in) -> std::pair<std::vector<int>, int> {
            auto nums = Parse::intVecBracketed(in);
            int pivot = 0; in >> pivot;
            return {nums, pivot};
        },
        Parse::intVec,                                          // output: space-separated ints
        [](auto p) { return Solution().pivotArray(p.first, p.second); }
    );
    return 0;
}
