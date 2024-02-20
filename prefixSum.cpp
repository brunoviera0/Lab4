#include "prefixSum.h"

using namespace std;

bool non_neg_prefix_sum(const vector<int>& lst){
    int sum = 0;
    for (int num : lst) { //iterate through lst
        sum += num; // add the current element to sum
        if (sum < 0) {
            return false;
        }
    }
    return true; // returns true if the sum is never negative
}


bool non_pos_prefix_sum(const vector<int>& lst){
    int sum = 0;
    for (int num : lst) { //iterate through lst
        sum += num; //add current element to sum
        if (sum > 0) {
            return false;
        }
    }
    return true; //returns true if sum never goes above 0

}
