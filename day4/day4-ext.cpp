#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[]) {
  string line;
  int ans = 0;
  int idx = 1;
  map<int, int> scores;
  while (getline(cin, line)) {
    cout << line << endl;

    int index = line.find(":");

    line = line.substr(index + 1);
    index = line.find("|");

    auto left = line.substr(0, index);
    unordered_set<int> winning_cards;
    stringstream ss_left(left);

    int val;
    while (ss_left >> val) {
      winning_cards.insert(val);
    }

    auto right = line.substr(index + 1);
    stringstream ss_right(right);

    int total = 0;

    while (ss_right >> val) {
      auto exists = winning_cards.count(val);
      if (exists) {
        total += 1;
      }
    }
    scores[idx]++;
    for (int i = 1; i <= total; i++) {
      scores[idx + i] += scores[idx];
    }

    for (auto &score : scores) {
      cout << score.first << "\t" << score.second << endl;
    }
    idx++;
  }
  int sum = 0;
  for_each(scores.begin(), scores.end(),
           [&](auto score) { sum += score.second; });

  cout << sum << endl;

  return 0;
}
