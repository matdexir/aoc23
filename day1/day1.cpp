#include <ctype.h>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  std::string line;
  long unsigned int total = 0;
  while (std::cin >> line) {
    std::string first;
    std::string last;
    for (auto &ch : line) {
      if (isdigit(ch)) {
        if (first.empty()) {
          first = ch;
          last = ch;
        }
        last = ch;
      }
    }
    total += std::stoi(first) * 10 + std::stoi(last);
    std::cout << total << std::endl;
  }
  std::cout << total << std::endl;

  return 0;
}
