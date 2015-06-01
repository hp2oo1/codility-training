// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++11
    float sqrt_N = sqrt(N);
    int count(0);
    for(int a=floor(sqrt_N); a>0; a--) {
        if( N%a==0 ) {
            count++;
        }
    }
    if( N==floor(sqrt_N)*floor(sqrt_N) )
        return 2*count-1;
    else
        return 2*count;
}
