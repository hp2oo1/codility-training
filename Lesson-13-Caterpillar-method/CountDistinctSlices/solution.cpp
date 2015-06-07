// Correctness 100%
// Performance 100%
// Task score 100%

// Note: codility may have a bug here
// because random access for vector should be O(1)
// i.e. performance will be not affected by N
// but in the codility test, the performance drops linear like O(N)
// I was wrong about this.. it is nothing to do with vector or codility test
// my previous algorithm is O(M^2) rather than O(N) as I desired.

// you can use includes, for example:
// #include <algorithm>
#include <bitset>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int M, vector<int> &A) {
    // write your code in C++11
    long i(0); // back index
    long j(0); // front index
    long k(0); 
    long count(0); // count of distinct slices
    bitset<100001> mybitset; // default all bits as 0 (unvisited)
    while( i<A.size() ) {
        if( j<A.size() ) {
            // if A[j] not visited before
            if( mybitset[A[j]]==0 ) {
                // mark it as visited
                mybitset[A[j]]= 1;
                // move front index to next one
                j++;
            }
            // found duplicated A[j]
            else {
                // store back index
                k=i;
                // move back index until matching
                while( A[i]!=A[j] ) {
                    // clear it as unvisited
                    mybitset[A[i]]= 0;
                    // move back index to next one
                    i++;
                }
                mybitset[A[i]]= 0;
                i++; // now i becomes new back index
                // number of distinct slices for index range [k,j-1]
                count += (j-k+1)*(j-k)/2;
                // minus number of distinct slices for index range [i,j-1] (overlap of next iteration
                count -= (j-i+1)*(j-i)/2;
            }
        }
        // j reaches the end
        else {
            // count last distinct slices
            count += (j-i+1)*(j-i)/2;
            // update i reaches the end and end loop
            i=j;
        }
        if( count>1000000000 )
            return 1000000000;
    }
    return count;
}
