/*
Correctness 100%
Performance 100%
Task score 100%
Detected time complexity:
O(L)
test	time	result
Example tests
example 
example test	0.009 s	OK
Correctness tests
extreme 
extreme small values	0.009 s	OK
small_functional 
small functional	0.009 s	OK
small 
small tests	0.009 s	OK
small_random 
small random, length = ~100	0.009 s	OK
Performance tests
medium_random 
medium random, length = ~1,000	0.009 s	OK
large_range 
large range, length = ~30,000	0.025 s	OK
large_random 
large random, length = ~30,000	0.025 s	OK
extreme_large 
all max size of the ladder	0.026 s	OK
*/

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> process(int N, int P) {
    vector<int> fib(N+2,0);
    fib[0] = 0;
    fib[1] = 1;
    for(unsigned int i=2; i<N+2; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
        int b = floor(pow(2,P));
        // avoid overflow
        fib[i] = fib[i] % b;
        // cout << fib << endl;
    }
    return fib;
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
    vector<int> fib = process( N, P );
    
    vector<int> C(A.size(),0);
    for(unsigned int i=0; i<A.size(); ++i) {
        int c = fib[A[i]+1];
        int d = floor(pow(2,B[i]));
        C[i] = c % d;
    }
    
    return C;
}
