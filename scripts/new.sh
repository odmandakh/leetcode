#!/usr/bin/env bash
# Scaffold a new problem: creates problems/<bucket>/<n>.cpp + tests/<bucket>/<n>/, then switches to it.
# Usage: scripts/new.sh <problem-number> ["<Title>"] [shape] [methodName] [--tests N]
#
# If [shape] and [methodName] are both given, generates a fully-wired run()
# for that signature shape (no "TODO: pick parser" left). Otherwise falls back
# to the generic stub, for one-off/exotic signatures (see problems/3161.cpp).
#
# --tests N (or -t N) creates N empty <k>.in/<k>.out placeholder pairs in the
# tests/ directory, ready to paste LeetCode's examples into. Defaults to 3.
# It's a flag rather than a positional arg so it doesn't collide with
# [shape]/[methodName] and can appear anywhere on the command line.
set -euo pipefail

tests_count=3
positional=()
while [ $# -gt 0 ]; do
    case "$1" in
    --tests | -t)
        tests_count="$2"
        shift 2
        ;;
    *)
        positional+=("$1")
        shift
        ;;
    esac
done
set -- "${positional[@]+"${positional[@]}"}"

if ! [[ "$tests_count" =~ ^[0-9]+$ ]] || [ "$tests_count" -eq 0 ]; then
    echo "--tests must be a positive integer" >&2
    exit 1
fi

print_shapes() {
    cat >&2 <<'TABLE'
Known shapes (scripts/new.sh <number> "<Title>" <shape> <methodName>):
  vec              vector<int> f(vector<int>&)          -> vector<int>
  vec-scalar       int f(vector<int>&)                  -> int
  vec-int          vector<int> f(vector<int>&, int)     -> vector<int>
  vec-int-scalar   int f(vector<int>&, int)              -> int
  matrix           vector<int> f(vector<vector<int>>&)  -> vector<int>
  scalar-vec-scalar int f(int, vector<int>&)             -> int
  matrix-vec-scalar int f(vector<vector<int>>&, vector<int>&) -> int
  str-scalar-str   string f(string, long long)           -> string
  str-scalar       int f(string)                         -> int    (quotes stripped)
  two-str-scalar   int f(string, string)                 -> int    (quotes stripped)
  str-query        vector<int> f(string, string, vector<int>&) -> vector<int>

Test fixture convention: one field per line, arrays bracketed (e.g. [1,2,3]),
scalars plain (e.g. 2) -- matches copy-pasting LeetCode's own Example text.

Omit shape/methodName entirely for the generic TODO-stub fallback.
TABLE
}

if [ $# -lt 1 ]; then
    echo "Usage: $0 <problem-number> [\"<Title>\"] [shape] [methodName] [--tests N]" >&2
    print_shapes
    exit 1
fi

n="$1"
title="${2:-Problem $n}"
shape="${3:-}"
method="${4:-}"
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# Problems are grouped into number-range subfolders, e.g. problems/2000-2999/2161.cpp
bucket_start=$(( (n/1000)*1000 ))
bucket_end=$((bucket_start+999))
bucket="${bucket_start}-${bucket_end}"
file="$root/problems/${bucket}/${n}.cpp"

if [ -e "$file" ]; then
    echo "problems/${bucket}/${n}.cpp already exists" >&2
    exit 1
fi

if [ -n "$shape" ] && [ -z "$method" ]; then
    echo "shape given but methodName is missing" >&2
    print_shapes
    exit 1
fi

mkdir -p "$root/problems/${bucket}" "$root/tests/${bucket}/${n}"

for ((i = 1; i <= tests_count; i++)); do
    : >"$root/tests/${bucket}/${n}/${i}.in"
    : >"$root/tests/${bucket}/${n}/${i}.out"
done

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
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
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
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
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
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
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
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
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
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
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
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
      "${title}",
      Parse::int2DVecBracketed,  // input: [[0,1,1],[1,0,1],...]
      Parse::intVecBracketed,    // output: [1,2,3,...]
      [](auto d) { return Solution().${method}(d); }
  );
}
EOF
    ;;

scalar-vec-scalar)
    cat > "$file" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  int ${method}(int n, vector<int>& nums) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
      "${title}",
      [](istream& in) -> pair<int, vector<int>> {
        int n = 0;
        in >> n;
        auto nums = Parse::intVecBracketed(in);
        return {n, nums};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().${method}(p.first, p.second)}; }
  );
}
EOF
    ;;

matrix-vec-scalar)
    cat > "$file" <<EOF
#include "runner.h"
#include <vector>

using namespace std;

class Solution {
 public:
  int ${method}(vector<vector<int>>& grid, vector<int>& nums) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
      "${title}",
      [](istream& in) -> pair<vector<vector<int>>, vector<int>> {
        auto grid = Parse::int2DVecBracketed(in);
        auto nums = Parse::intVecBracketed(in);
        return {grid, nums};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().${method}(p.first, p.second)}; }
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
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
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

str-scalar)
    cat > "$file" <<EOF
#include "runner.h"
#include <string>

using namespace std;

class Solution {
 public:
  int ${method}(string s) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
      "${title}",
      Parse::quotedString,  // input: "abc" or 'abc' (quotes stripped)
      Parse::intVec,        // output: single int (as a 1-element vector)
      [](auto s) { return vector<int>{Solution().${method}(s)}; }
  );
}
EOF
    ;;

two-str-scalar)
    cat > "$file" <<EOF
#include "runner.h"
#include <string>

using namespace std;

class Solution {
 public:
  int ${method}(string a, string b) {
    // TODO: implement
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
      "${title}",
      [](istream& in) -> pair<string, string> {
        string a = Parse::quotedString(in);
        string b = Parse::quotedString(in);
        return {a, b};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().${method}(p.first, p.second)}; }
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
      string(PROJECT_ROOT) + "/tests/${bucket}/${n}",
      "${title}",
      [](istream& in) -> tuple<string, string, vector<int>> {
        string s = Parse::quotedString(in);
        string qc = Parse::quotedString(in);
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

echo "Created problems/${bucket}/${n}.cpp and tests/${bucket}/${n}/ (${tests_count} empty .in/.out pair(s))"
"$root/scripts/switch.sh" "$n"
