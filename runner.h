#pragma once
#include <iostream>
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

