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
    int i(0);
    int j(0);
    long count(0);
    bitset<100000> mybitset;
    while( i<A.size() ) {
        // cout << i << " " << j << " ";
        if( j<A.size() ) {
            if( mybitset[A[j]]==0 ) {
                mybitset[A[j]]= 1;
                count++;
                j++;
            }
            else {
                mybitset.reset();
                i++;
                j=i;
            }
        }
        else {
            count += (j-i)*(j-i-1)/2;
            i=j;
        }
        if( count>1000000000 )
            return 1000000000;
        // cout << count << endl;
    }
    return count;
}
