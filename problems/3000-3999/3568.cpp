#include <queue>
#include <tuple>
#include <vector>

#include "runner.h"

using namespace std;

// ASSISTED: AI provided the BFS-with-state (x, y, mask, energy) solution logic directly.
class Solution {
 public:
  int minMoves(vector<string>& classroom, int energy) {
    int rows = classroom.size();
    int cols = classroom[0].size();

    int sx = -1, sy = -1;
    vector<pair<int, int>> garbageCells;
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (classroom[r][c] == 'S') {
          sx = r;
          sy = c;
        } else if (classroom[r][c] == 'L') {
          garbageCells.push_back({r, c});
        }
      }
    }

    int numGarbage = garbageCells.size();
    int fullMask = (1 << numGarbage) - 1;
    if (fullMask == 0) return 0;  // no garbage at all

    vector<vector<int>> bitIndexGrid(rows, vector<int>(cols, -1));
    for (int i = 0; i < numGarbage; ++i) {
      bitIndexGrid[garbageCells[i].first][garbageCells[i].second] = i;
    }

    int maskSize = 1 << numGarbage;
    int eSize = energy + 1;
    auto encode = [&](int x, int y, int mask, int e) {
      return ((x * cols + y) * maskSize + mask) * eSize + e;
    };

    vector<bool> visited(rows * cols * maskSize * eSize, false);
    queue<tuple<int, int, int, int, int>> q;  // (x, y, mask, e, steps)

    q.push({sx, sy, 0, energy, 0});
    visited[encode(sx, sy, 0, energy)] = true;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
      auto [x, y, mask, e, steps] = q.front();
      q.pop();

      if (mask == fullMask) return steps;

      for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
        if (classroom[nx][ny] == 'X') continue;  // obstacle -- confirm this symbol

        int ne = e - 1;
        if (ne < 0) continue;  // out of energy -- this move is invalid, prune

        int nmask = mask;
        if (classroom[nx][ny] == 'R') {
          ne = energy;  // recharge overrides the decrement
        } else if (classroom[nx][ny] == 'L') {
          nmask |= (1 << bitIndexGrid[nx][ny]);
        }

        int idx = encode(nx, ny, nmask, ne);
        if (visited[idx]) continue;
        visited[idx] = true;
        q.push({nx, ny, nmask, ne, steps + 1});
      }
    }

    return -1;
  }
};

inline void run() {
  runTests(
      string(PROJECT_ROOT) + "/tests/3000-3999/3568", "Minimum Moves to Clean the Classroom",
      [](istream& in) -> pair<vector<string>, int> {
        auto classroom = Parse::strVecBracketed(in);
        int energy = 0;
        in >> energy;
        return {classroom, energy};
      },
      Parse::intVec,  // output: single int (as a 1-element vector)
      [](auto p) { return vector<int>{Solution().minMoves(p.first, p.second)}; });
}
