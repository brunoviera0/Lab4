#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "balanced_seq.h"
#include "fisher_yates.h"
#include "prefixSum.h"


TEST_CASE("Well-Balanced Sequence for n=0") {
    auto sequence = generate_sequence(0, '<', '>'); 
    CHECK(sequence.empty()); //check if the sequence is empty
}


TEST_CASE("Well-Balanced Sequence for only 1 pair (n=1)") {
    auto sequence = generate_sequence(1, '(', ')');
    CHECK(sequence.size() == 2);
    CHECK(sequence[0] == '(');
    CHECK(sequence[1] == ')');
}

TEST_CASE("Well-Balanced Sequence for n=3") {
    auto sequence = generate_sequence(3, '[', ']');
    CHECK(sequence.size() == 6);
    int balance = 0;
    for (char c : sequence) {
        balance += (c == '[') ? 1 : -1;
        CHECK(balance >= 0); //ensure non-neg throughout
    }
    CHECK(balance == 0); 
}

TEST_CASE("Well-Balanced Sequence for larger number pairs (n=5)") {
    auto sequence = generate_sequence(5, '{', '}');
    CHECK(sequence.size() == 10);
    int balance = 0;
    for (char c : sequence) {
        balance += (c == '{') ? 1 : -1;
        CHECK(balance >= 0);
    }
    CHECK(balance == 0);
}

TEST_CASE("Fisher-Yates Shuffle Preserves Elements") {
    std::vector<int> original = {1, -1, 1, -1, 1};
    std::vector<int> shuffled = original;
    fisher_yates(shuffled);
    std::sort(original.begin(), original.end());
    std::sort(shuffled.begin(), shuffled.end());
    CHECK(original == shuffled);
}

TEST_CASE("Non-Negative Prefix Sums for Known Balanced Sequence") {
    std::vector<int> sequence = {1, -1, 1, 1, -1, -1}; //balanced
    bool nonNegativePrefix = true;
    int sum = 0;
    for (int val : sequence) {
        sum += val;
        if (sum < 0) {
            nonNegativePrefix = false;
            break;
        }
    }
    CHECK(nonNegativePrefix);
}
