#!/usr/bin/env bash
# Scaffold a new problem: creates problems/<n>.cpp + tests/<n>/, then switches to it.
# Usage: scripts/new.sh <problem-number> ["<Title>"] [shape] [methodName]
#
# If [shape] and [methodName] are both given, generates a fully-wired run()
# for that signature shape (no "TODO: pick parser" left). Otherwise falls back
# to the generic stub, for one-off/exotic signatures (see problems/3161.cpp).
set -euo pipefail

print_shapes() {
    cat >&2 <<'TABLE'
Known shapes (scripts/new.sh <number> "<Title>" <shape> <methodName>):
  vec              vector<int> f(vector<int>&)          -> vector<int>
  vec-scalar       int f(vector<int>&)                  -> int
  vec-int          vector<int> f(vector<int>&, int)     -> vector<int>
  vec-int-scalar   int f(vector<int>&, int)              -> int
  matrix           vector<int> f(vector<vector<int>>&)  -> vector<int>
  str-scalar-str   string f(string, long long)           -> string
  str-query        vector<int> f(string, string, vector<int>&) -> vector<int>

Test fixture convention: one field per line, arrays bracketed (e.g. [1,2,3]),
scalars plain (e.g. 2) -- matches copy-pasting LeetCode's own Example text.

Omit shape/methodName entirely for the generic TODO-stub fallback.
TABLE
}

if [ $# -lt 1 ]; then
    echo "Usage: $0 <problem-number> [\"<Title>\"] [shape] [methodName]" >&2
    print_shapes
    exit 1
fi

n="$1"
title="${2:-Problem $n}"
shape="${3:-}"
method="${4:-}"
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
file="$root/problems/${n}.cpp"

if [ -e "$file" ]; then
    echo "problems/${n}.cpp already exists" >&2
    exit 1
fi

if [ -n "$shape" ] && [ -z "$method" ]; then
    echo "shape given but methodName is missing" >&2
    print_shapes
    exit 1
fi

mkdir -p "$root/tests/${n}"

case "$shape" in
"")
    cat > "$file" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  // TODO: implement
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${n}",
      "${title}",
      Parse::intVec,                              // TODO: pick parser
      Parse::intVec,                              // TODO: pick parser
      [](auto d) { return Solution().TODO(d); }   // TODO: solve
  );
}
EOF
    ;;

vec)
    cat > "$file" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> ${method}(vector<int>& nums) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${n}",
      "${title}",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVecBracketed,  // output: [1,2,3,...]
      [](auto d) { return Solution().${method}(d); }
  );
}
EOF
    ;;

vec-scalar)
    cat > "$file" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  int ${method}(vector<int>& nums) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${n}",
      "${title}",
      Parse::intVecBracketed,  // input: [1,2,3,...]
      Parse::intVec,           // output: single int (as a 1-element vector)
      [](auto d) { return vector<int>{Solution().${method}(d)}; }
  );
}
EOF
    ;;

vec-int)
    cat > "$file" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> ${method}(vector<int>& nums, int x) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${n}",
      "${title}",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int x = 0;
        in >> x;
        return {nums, x};
      },
      Parse::intVec,  // output: space-separated ints
      [](auto p) { return Solution().${method}(p.first, p.second); }
  );
}
EOF
    ;;

vec-int-scalar)
    cat > "$file" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  int ${method}(vector<int>& nums, int x) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${n}",
      "${title}",
      [](istream& in) -> pair<vector<int>, int> {
        auto nums = Parse::intVecBracketed(in);
        int x = 0;
        in >> x;
        return {nums, x};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().${method}(p.first, p.second)}; }
  );
}
EOF
    ;;

matrix)
    cat > "$file" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> ${method}(vector<vector<int>>& matrix) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${n}",
      "${title}",
      Parse::int2DVecBracketed,  // input: [[0,1,1],[1,0,1],...]
      Parse::intVecBracketed,    // output: [1,2,3,...]
      [](auto d) { return Solution().${method}(d); }
  );
}
EOF
    ;;

str-scalar-str)
    cat > "$file" <<EOF
#include "runner.h"
#include <string>

using namespace std;

class Solution {
 public:
  string ${method}(string s, long long t) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${n}",
      "${title}",
      [](istream& in) -> pair<string, long long> {
        string s;
        long long t;
        in >> s >> t;
        return {s, t};
      },
      Parse::strVec,
      [](auto p) { return vector<string>{Solution().${method}(p.first, p.second)}; }
  );
}
EOF
    ;;

str-query)
    cat > "$file" <<EOF
#include "runner.h"
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> ${method}(string s, string queryCharacters, vector<int>& queryIndices) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${n}",
      "${title}",
      [](istream& in) -> tuple<string, string, vector<int>> {
        auto stripQuotes = [](string s) {
          if (s.size() >= 2 && s.front() == '"' && s.back() == '"') s = s.substr(1, s.size() - 2);
          return s;
        };
        string s, qc;
        in >> s >> qc;
        s = stripQuotes(s);
        qc = stripQuotes(qc);
        auto indices = Parse::intVecBracketed(in);
        return {s, qc, indices};
      },
      Parse::intVecBracketed,  // output: [3,3,4]
      [](auto t) {
        auto [s, qc, idx] = t;
        return Solution().${method}(s, qc, idx);
      }
  );
}
EOF
    ;;

*)
    echo "Unknown shape: ${shape}" >&2
    print_shapes
    exit 1
    ;;
esac

echo "Created problems/${n}.cpp and tests/${n}/"
"$root/scripts/switch.sh" "$n"
