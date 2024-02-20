#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "balanced_seq.h"


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
