// Correctness 100%
// Performance 80%
// Task score 90%

// you can use includes, for example:
// #include <algorithm>
#include <bitset>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int M, vector<int> &A) {
    // for(unsigned int i=0; i<A.size(); ++i)
        // cout << A[i] << " ";
    // cout << endl;
    // write your code in C++11
    long i(0);
    long j(0);
    long k(0);
    long count(0);
    bitset<100001> mybitset;
    vector<long> myvector(100001,0);
    while( i<A.size() ) {
        // cout << i << " " << j << " ";
        if( j<A.size() ) {
            if( mybitset[A[j]]==0 ) {
                mybitset[A[j]]= 1;
                myvector[A[j]]= j;
                j++;
            }
            else {
                k=myvector[A[j]];
                // cout << i << " " << k << " " << j << endl;
                count += (j-i+2)*(j-i+1)/2;
                count -= k-i+1;
                count -= (j-k+1)*(j-k)/2;
                i=k+1;
                j=i;
                mybitset.reset();
            }
        }
        else {
            count += (j-i+1)*(j-i)/2;
            i=j;
        }
        if( count>1000000000 )
            return 1000000000;
        // cout << count << endl;
    }
    return count;
}
