#include "balanced_seq.h"
#include <iostream>
#include <vector>

int main() {
    srand((unsigned)time(0));

    int n;
    char first_symbol, last_symbol;
    std::cout << "Enter the number of symbol pairs: ";
    std::cin >> n;
    std::cout << "Enter the first(opening) symbol: ";
    std::cin >> first_symbol;
    std::cout << "Enter the last(closing) symbol: ";
    std::cin >> last_symbol;

    auto sequence = generate_sequence(n, first_symbol, last_symbol);

    for (char symbol : sequence) {
        std::cout << symbol;
    }
    std::cout << std::endl;

    return 0;
}
