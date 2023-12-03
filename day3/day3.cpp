#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  string line;
  vector<vector<pair<char, bool>>> graph;
  vector<pair<int, int>> symbols;
  int ROWS = 0;
  int COLS = 0;
  while (cin >> line) {
    vector<pair<char, bool>> buffer;
    for (int i = 0; i < line.size(); i++) {
      if (not isdigit(line[i]) and line[i] != '.') {
        symbols.push_back(make_pair(ROWS, i));
      }
      buffer.push_back(make_pair(line[i], false));
    }
    graph.push_back(buffer);
    ROWS++;
    COLS = line.size();
  }

  while (symbols.size()) {
    auto [i, j] = symbols.back();
    symbols.pop_back();
    for (int di = -1; di < 2; di++) {
      for (int dj = -1; dj < 2; dj++) {
        int nxt_i = i + di;
        int nxt_j = j + dj;
        if (0 <= nxt_i < COLS and 0 <= nxt_j < ROWS) {
          if (isdigit(graph[nxt_i][nxt_j].first))
            graph[nxt_i][nxt_j].second = true;
        }
      }
    }
  }
  int ans = 0;
  for (auto &graph_line : graph) {
    int line_idx = 0;
    while (line_idx < graph_line.size()) {
      if (isdigit(graph_line[line_idx].first)) {
        if (line_idx == 0 or not isdigit(graph_line[line_idx - 1].first)) {
          int value = 0;
          bool around = false;
          while (line_idx < graph_line.size() and
                 isdigit(graph_line[line_idx].first)) {
            value = value * 10 + atoi(&graph_line[line_idx].first);
            around = around or graph_line[line_idx].second;
            line_idx++;
          }
          if (around) {
            ans += value;
          }
          cout << value << "->" << around << endl;
        }
      }
      line_idx++;
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
