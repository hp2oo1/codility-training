// Correctness 100%
// Performance 80%
// Task score 90%

// Note: codility may have a bug here
// because random access for vector should be O(1)
// i.e. performance will be not affected by N
// but in the codility test, the performance drops linear like O(N)

// you can use includes, for example:
// #include <algorithm>
#include <bitset>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int M, vector<int> &A) {
    // write your code in C++11
    long i(0); // back index
    long j(0); // front index
    long k(0); // new back index
    long count(0); // count of distinct slices
    bitset<100001> mybitset; // default all bits as 0 (unvisited)
    vector<long> myvector(100001,-1);
    while( i<A.size() ) {
        if( j<A.size() ) {
            // if A[j] not visited before
            if( mybitset[A[j]]==0 ) {
                // mark it as visited
                mybitset[A[j]]= 1;
                // record its index
                myvector[A[j]]= j;
                // move front index to next one
                j++;
            }
            else {
                // k is the index of previous A[j] appears
                k=myvector[A[j]];
                // the total number of slices between i and j
                count += (j-i+2)*(j-i+1)/2;
                // minus the number of slices which are not distinct
                count -= k-i+1;
                // minus the number of slices which will be repeated once i updates to k+1
                count -= (j-k+1)*(j-k)/2;
                // update i to k+1
                i=k+1;
                // reset j to i
                j=i;
                // reset all bits as 0 (unvisited)
                mybitset.reset();
            }
        }
        else {
            // when j reaches the end, count last distinct slices
            count += (j-i+1)*(j-i)/2;
            // update i reaches the end
            i=j;
        }
        if( count>1000000000 )
            return 1000000000;
    }
    return count;
}
