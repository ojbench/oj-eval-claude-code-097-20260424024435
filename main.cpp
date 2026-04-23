#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

int main() {
    std::string input;
    std::string line;
    while (std::getline(std::cin, line)) {
        input += line + " ";
    }

    if (input.empty()) return 0;

    std::vector<int> nodes;
    int cnt = 0;

    // The input format is "root = [12, 5, 18, 2, 9, 15, 20], cnt = 4"
    // We can just extract all numbers. The last one is cnt.

    for (size_t i = 0; i < input.length(); ++i) {
        if (std::isdigit(input[i])) {
            size_t j = i;
            while (j < input.length() && std::isdigit(input[j])) {
                j++;
            }
            int val = std::stoi(input.substr(i, j - i));
            nodes.push_back(val);
            i = j;
        }
    }

    if (nodes.size() < 2) {
        // This case shouldn't happen based on constraints, but safety first.
        return 0;
    }

    cnt = nodes.back();
    nodes.pop_back();

    std::sort(nodes.begin(), nodes.end(), std::greater<int>());

    if (cnt > 0 && cnt <= static_cast<int>(nodes.size())) {
        std::cout << nodes[cnt - 1] << std::endl;
    }

    return 0;
}
