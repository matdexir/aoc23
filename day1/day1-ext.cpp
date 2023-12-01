#include <ctype.h>
#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char *argv[]) {

  std::string line;
  long unsigned int total = 0;
  const std::unordered_map<std::string, int> keywords = {
      {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
      {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"zero", 0}};

  while (std::cin >> line) {
    int first = -1;
    int last = -1;
    for (int i = 0; i < line.size(); i++) {
      int tmp = -1;
      if (isdigit(line[i])) {
        switch (line[i]) {
        case '0':
          tmp = 0;
          break;
        case '1':
          tmp = 1;
          break;
        case '2':
          tmp = 2;
          break;
        case '3':
          tmp = 3;
          break;
        case '4':
          tmp = 4;
          break;
        case '5':
          tmp = 5;
          break;
        case '6':
          tmp = 6;
          break;
        case '7':
          tmp = 7;
          break;
        case '8':
          tmp = 8;
          break;
        case '9':
          tmp = 9;
          break;
        default:
          tmp = -1;
          break;
        }
      } else {
        for (auto &key : keywords) {
          auto idx = line.substr(i).find(key.first);
          std::cout << idx << "\t" << key.first << "\t" << line.substr(i)
                    << std::endl;
          if (idx == 0) {
            tmp = key.second;
          }
        }
      }
      if (tmp != -1) {
        if (first == -1)
          first = tmp;
        last = tmp;
      }
      std::cout << first << "\t" << last << std::endl;
    }
    total += first * 10 + last;
    // std::cout << total << std::endl;
  }
  std::cout << total << std::endl;

  return 0;
}
