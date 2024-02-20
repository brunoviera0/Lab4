#include "balanced_seq.h"
#include "fisher_yates.h"
#include <cstdlib> //rand()

bool is_balanced(const std::vector<int>& sequence) {
    int balance = 0;
    for (int i : sequence) {
        balance += i;
        if (balance < 0) 
            return false;
    }
    return balance == 0;
}

std::vector<char> generate_sequence(int n, char first_symbol, char last_symbol) {
    if (n == 0) {
        return std::vector<char>();
    }
    std::vector<int> sequence(2 * n);
    std::vector<char> char_sequence(2 * n);
    for (int i = 0; i < n; ++i) 
        sequence[i] = 1; //first symbol
    for (int i = n; i < 2 * n; ++i) 
        sequence[i] = -1; //last symbol

    do {
        fisher_yates(sequence);
    } while (!is_balanced(sequence));

    for (int i = 0; i < sequence.size(); ++i) {
        char_sequence[i] = sequence[i] == 1 ? first_symbol : last_symbol;
    }

    return char_sequence;
}
