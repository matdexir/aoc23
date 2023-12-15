#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[]) {
  string line;
  int ans = 0;
  while (getline(cin, line)) {
    cout << line << endl;
    int index = line.find(":");
    cout << "index: " << index << endl;
    line = line.substr(index + 1);
    index = line.find("|");
    auto left = line.substr(0, index);
    unordered_set<int> winning_cards;
    stringstream ss_left(left);
    int val;
    while (ss_left >> val) {
      cout << "VAL:\t" << val << endl;
      winning_cards.insert(val);
    }
    unordered_set<int> playing_cards;
    auto right = line.substr(index + 1);
    stringstream ss_right(right);
    int total = 0;
    while (ss_right >> val) {
      auto exists = winning_cards.count(val);
      if (exists) {
        total = (total == 0) ? 1 : total * 2;
      }
    }
    cout << left << "\t" << right << endl;
    cout << total << endl;
    ans += total;
  }
  cout << ans << endl;

  return 0;
}
