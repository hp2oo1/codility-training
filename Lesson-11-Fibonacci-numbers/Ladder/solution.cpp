/*
You have to climb up a ladder. The ladder has exactly N rungs, numbered from 1 to N. With each step, you can ascend by one or two rungs. More precisely:

with your first step you can stand on rung 1 or 2,
if you are on rung K, you can move to rungs K + 1 or K + 2,
finally you have to stand on rung N.
Your task is to count the number of different ways of climbing to the top of the ladder.

For example, given N = 4, you have five different ways of climbing, ascending by:

1, 1, 1 and 1 rung,
1, 1 and 2 rungs,
1, 2 and 1 rung,
2, 1 and 1 rungs, and
2 and 2 rungs.
Given N = 5, you have eight different ways of climbing, ascending by:

1, 1, 1, 1 and 1 rung,
1, 1, 1 and 2 rungs,
1, 1, 2 and 1 rung,
1, 2, 1 and 1 rung,
1, 2 and 2 rungs,
2, 1, 1 and 1 rungs,
2, 1 and 2 rungs, and
2, 2 and 1 rung.
The number of different ways can be very large, so it is sufficient to return the result modulo 2P, for a given integer P.

Assume that the following declarations are given:

struct Results {
  int * C;
  int L;
};

Write a function:

struct Results solution(int A[], int B[], int L);

that, given two non-empty zero-indexed arrays A and B of L integers, returns an array consisting of L integers specifying the consecutive answers; position I should contain the number of different ways of climbing the ladder with A[I] rungs modulo 2B[I].

For example, given L = 5 and:

    A[0] = 4   B[0] = 3
    A[1] = 4   B[1] = 2
    A[2] = 5   B[2] = 4
    A[3] = 5   B[3] = 3
    A[4] = 1   B[4] = 1
the function should return the sequence [5, 1, 8, 0, 1], as explained above.

Assume that:

L is an integer within the range [1..30,000];
each element of array A is an integer within the range [1..L];
each element of array B is an integer within the range [1..30].
Complexity:

expected worst-case time complexity is O(L);
expected worst-case space complexity is O(L), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

Copyright 2009–2015 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<long> process(int N, int P) {
    vector<long> fib_cache(N+2,0);
    fib_cache[0] = 0;
    fib_cache[1] = 1;
    long fib_2(0);
    long fib_1(1);
    for(unsigned int i=2; i<N+2; ++i) {
        long fib = fib_1 + fib_2;
        fib_2 = fib_1;
        fib_1 = fib;
        long b = floor(pow(2,P));
        fib_cache[i] = fib % b;
        // cout << fib << endl;
    }
    return fib_cache;
}

int findMax(vector<int> &A) {
    int max(A[0]);
    for(unsigned int i=0; i<A.size(); ++i) {
        if( max<A[i] ) {
            max=A[i];
        }
    }
    return max;
}

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    int N = findMax( A );
    int P = findMax( B );
    vector<long> fib_cache = process( N, P );
    
    vector<int> C(A.size(),0);
    for(unsigned int i=0; i<A.size(); ++i) {
        long c = fib_cache[A[i]+1];
        long d = floor(pow(2,B[i]));
        C[i] = c % d;
    }
    
    return C;
}
