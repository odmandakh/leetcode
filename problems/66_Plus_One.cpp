#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../runner.h"

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;  // carry
        }
        // All digits were 9 → prepend 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// ─── Auto test runner ─────────────────────────────────────────────────────────

inline void runTests(const std::string& testDir) {
    namespace fs = std::filesystem;

    std::vector<fs::path> inFiles;
    for (auto& entry : fs::directory_iterator(testDir)) {
        if (entry.path().extension() == ".in")
            inFiles.push_back(entry.path());
    }
    std::sort(inFiles.begin(), inFiles.end());

    int passed = 0;
    int total  = static_cast<int>(inFiles.size());

    std::cout << "Problem 66 · Plus One\n";
    std::cout << std::string(35, '-') << "\n";

    for (auto& inPath : inFiles) {
        // ── read input (single line of space-separated digits) ─────────────
        std::ifstream fin(inPath);
        std::vector<int> digits;
        std::string line;
        while (std::getline(fin, line)) {
            if (line.empty() || line[0] == '#') continue;
            std::istringstream iss(line);
            int v;
            while (iss >> v) digits.push_back(v);
        }

        // ── read expected output ───────────────────────────────────────────
        fs::path outPath = inPath;
        outPath.replace_extension(".out");
        std::ifstream fout(outPath);
        std::vector<int> expected;
        int v;
        while (fout >> v) expected.push_back(v);

        // ── run solution ───────────────────────────────────────────────────
        Solution sol;
        auto actual = sol.plusOne(digits);

        bool pass = (actual == expected);
        if (pass) ++passed;

        reportResult("Case " + inPath.stem().string(), actual, expected);
    }

    std::cout << std::string(35, '-') << "\n";
    std::cout << "Result: " << passed << "/" << total << " passed\n\n";
}

