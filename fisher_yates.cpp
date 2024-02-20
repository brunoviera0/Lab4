#include "fisher_yates.h"
#include <vector>
#include <cstdlib> //rand()

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//updated fisher_yates function to work with std::vector<int>
void fisher_yates(std::vector<int>& array) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        int rnd_loc = std::rand() % (array.size() - i) + i;
        swap(array[i], array[rnd_loc]);
    }
}
