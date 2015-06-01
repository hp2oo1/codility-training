/*
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
small random, length = ~100	0.009 s	WRONG ANSWER 
got ..151, 7380601, 1175, -575, 304728, 267914.. expected ..151, 7380601, 1175, 7617, 304728, 267914..
Performance tests
medium_random
medium random, length = ~1,000	0.009 s	WRONG ANSWER 
got [-27, 23456, 5, -1875.. expected [485, 23456, 5, 173, ..
large_range 
large range, length = ~30,000	0.026 s	WRONG ANSWER 
got .., 30840, 5, 839613, -6398, 784063, -15, .. expected .., 30840, 5, 839613, 1794, 784063, 1, 524..
large_random 
large random, length = ~30,000	0.026 s	WRONG ANSWER 
got [93148797, -18980743, 94924585,.. expected [93148797, 14573689, 94924585, ..
extreme_large 
all max size of the ladder	0.027 s	RUNTIME ERROR 
tested program terminated unexpectedly
stderr:
Error during output processing. Make sure your program returns a value of correct type.
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
