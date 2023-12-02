#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  string line;
  int ans = 0;
  int power = 0;
  while (getline(cin, line)) {
    stringstream ss(line);
    string ID, color;
    unordered_map<string, int> counter;
    int count;
    ss >> ID >> ID;
    while (ss >> count >> color) {
      if (color.back() == ';' or color.back() == ',')
        color.pop_back();
      counter[color] = max(count, counter[color]);
      cout << count << color << endl;
    }

    if (counter["red"] <= 12 and counter["green"] <= 13 and
        counter["blue"] <= 14) {
      ans += stoi(ID);
    }
    power += counter["red"] * counter["green"] * counter["blue"];
  }
  cout << ans << endl;
  cout << power << endl;
}
