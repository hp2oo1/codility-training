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
