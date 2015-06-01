// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    int max_1(A[0]);
    int max_2(A[0]);
    for(unsigned int i=1; i<A.size(); ++i) {
        max_1 = max( max_1+A[i], A[i] );
        max_2 = max( max_2, max_1 );
    }
    return max_2;
}
