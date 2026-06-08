#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// ─── Generic print helper ─────────────────────────────────────────────────────

template<typename T>
inline void printVec(const std::vector<T>& v) {
    std::cout << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        if constexpr (std::is_same_v<T, bool>)
            std::cout << (v[i] ? "true" : "false");
        else
            std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << ']';
}

// ─── Generic result reporter ──────────────────────────────────────────────────

template<typename T>
inline void reportResult(
    const std::string& label,
    const std::vector<T>& actual,
    const std::vector<T>& expected
) {
    bool pass = (actual == expected);
    std::cout << "[" << (pass ? "PASS" : "FAIL") << "] " << label << "\n";
    std::cout << "  actual   = "; printVec(actual);   std::cout << "\n";
    if (!pass) {
        std::cout << "  expected = "; printVec(expected); std::cout << "\n";
    }
}

// ─── Pre-built parsers ────────────────────────────────────────────────────────
// Pick one for parseInput and one for parseExpected in runTests().

namespace Parse {
    // Space-separated integers on one line → vector<int>
    inline std::vector<int> intVec(std::istream& in) {
        std::vector<int> v;
        int x; while (in >> x) v.push_back(x);
        return v;
    }

    // Multiple lines, each with space-separated integers → vector<vector<int>>
    // Lines starting with '#' are treated as comments and ignored.
    inline std::vector<std::vector<int>> int2DVec(std::istream& in) {
        std::vector<std::vector<int>> res;
        std::string line;
        while (std::getline(in, line)) {
            if (line.empty() || line[0] == '#') continue;
            std::istringstream iss(line);
            std::vector<int> row;
            int x; while (iss >> x) row.push_back(x);
            if (!row.empty()) res.push_back(row);
        }
        return res;
    }

    // Space-separated "true"/"false" tokens → vector<bool>
    inline std::vector<bool> boolVec(std::istream& in) {
        std::vector<bool> v;
        std::string t; while (in >> t) v.push_back(t == "true");
        return v;
    }

    // Space-separated strings → vector<string>
    inline std::vector<std::string> strVec(std::istream& in) {
        std::vector<std::string> v;
        std::string t; while (in >> t) v.push_back(t);
        return v;
    }

    // Bracket/comma format: [1,2,3] or [-3,4,3,2] → vector<int>
    inline std::vector<int> intVecBracketed(std::istream& in) {
        std::vector<int> v;
        std::string line;
        while (std::getline(in, line)) {
            if (line.empty()) continue;
            // strip [ and ]
            for (char& c : line) if (c == '[' || c == ']') c = ' ';
            // replace commas with spaces
            for (char& c : line) if (c == ',') c = ' ';
            std::istringstream iss(line);
            int x; while (iss >> x) v.push_back(x);
            if (!v.empty()) break; // read only first non-empty line
        }
        return v;
    }
}

// ─── Generic test runner ──────────────────────────────────────────────────────
// parseInput    (std::istream&) -> InputT
// parseExpected (std::istream&) -> OutputT
// solve         (InputT)        -> OutputT

template<typename ParseIn, typename ParseOut, typename Solve>
inline void runTests(
    const std::string& testDir,
    const std::string& title,
    ParseIn   parseInput,
    ParseOut  parseExpected,
    Solve     solve
) {
    namespace fs = std::filesystem;

    std::vector<fs::path> inFiles;
    for (auto& entry : fs::directory_iterator(testDir))
        if (entry.path().extension() == ".in")
            inFiles.push_back(entry.path());
    std::sort(inFiles.begin(), inFiles.end());

    const int total = static_cast<int>(inFiles.size());
    int passed = 0;

    std::cout << title << "\n" << std::string(title.size(), '-') << "\n";

    for (auto& inPath : inFiles) {
        std::ifstream fin(inPath);
        auto input = parseInput(fin);

        fs::path outPath = inPath;
        outPath.replace_extension(".out");
        std::ifstream fout(outPath);
        auto expected = parseExpected(fout);

        auto actual = solve(input);

        bool pass = (actual == expected);
        if (pass) ++passed;
        reportResult("Case " + inPath.stem().string(), actual, expected);
    }

    std::cout << std::string(title.size(), '-') << "\n";
    std::cout << "Result: " << passed << "/" << total << " passed\n\n";
}




