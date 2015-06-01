// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// greatest common divisor
int gcd(int a, int b) {
    int c;
    while( a!=0 ) {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}

// least common multiple
long lcm(long a, long b) {
    return a*b/gcd(a,b);
}

int solution(int N, int M) {
    // write your code in C++11
    return lcm(N,M)/M;
}
