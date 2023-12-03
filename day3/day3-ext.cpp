#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  string line;

  vector<vector<pair<char, bool>>> graph;
  int ROWS = 0;
  int COLS = 0;

  while (cin >> line) {
    vector<pair<char, bool>> buffer;
    for (int i = 0; i < line.size(); i++) {
      buffer.push_back(make_pair(line[i], false));
    }
    graph.push_back(buffer);
    ROWS++;
    COLS = line.size();
  }

  map<pair<int, int>, vector<int>> star_value_neighbors;

  for (int row = 0; row < graph.size(); row++) {
    int col = 0;

    while (col < graph[row].size()) {
      if (isdigit(graph[row][col].first) and
          (col == 0 or not isdigit(graph[row][col - 1].first))) {
        int value = 0;
        int around = false;
        pair<int, int> star_pos;
        while (col < graph[row].size() and isdigit(graph[row][col].first)) {
          value = value * 10 + atoi(&graph[row][col].first);
          // cout << row << col << endl;
          for (int d_row = -1; d_row < 2; d_row++) {
            for (int d_col = -1; d_col < 2; d_col++) {
              int nxt_row = row + d_row;
              int nxt_col = col + d_col;
              if ((0 <= nxt_row and nxt_row < ROWS) and
                  (0 <= nxt_col and nxt_col < COLS) and
                  graph[nxt_row][nxt_col].first == '*') {
                around = true;
                star_pos = make_pair(nxt_row, nxt_col);
              }
            }
          }
          col++;
        }

        if (around) {
          if (star_value_neighbors.count(star_pos) == 0) {
            star_value_neighbors.insert(
                pair<pair<int, int>, vector<int>>(star_pos, vector<int>()));
          }
          star_value_neighbors[star_pos].push_back(value);
        }
      }
      col++;
    }
  }
  int ans = 0;
  for (auto it = star_value_neighbors.begin(); it != star_value_neighbors.end();
       it++) {
    auto [_, neighbors] = *it;
    if (neighbors.size() == 2) {
      ans += neighbors[0] * neighbors[1];
    }
  }
  for_each(graph.begin(), graph.end(), [](const auto &buff) {
    for (auto &b : buff)
      cout << "(" << b.first << "," << b.second << ") ";
    cout << endl;
  });
  cout << ans << endl;
  return 0;
}
