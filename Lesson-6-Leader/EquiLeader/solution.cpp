/*
A non-empty zero-indexed array A consisting of N integers is given.
The leader of this array is the value that occurs in more than half of the elements of A.
An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.
For example, given array A such that:
    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
we can find two equi leaders:
0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
The goal is to count the number of equi leaders.
Write a function:
int solution(vector<int> &A);
that, given a non-empty zero-indexed array A consisting of N integers, returns the number of equi leaders.
For example, given:
    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
the function should return 2, as explained above.
Assume that:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
Copyright 2009–2015 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

// you can use includes, for example:
// #include <algorithm>
#include <map>
#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> process(vector<int> &A, bool reverse) {
    vector<int> B(A.size(),0);
    map<int,int> mymap;
    for(unsigned int j=0; j<A.size(); ++j) {
        unsigned int i=j;
        if( reverse ) {
            i = A.size()-1-j;
        }
        pair<map<int,int>::iterator,bool> ret;
        ret = mymap.insert( make_pair(A[i],1) );
        if( ret.second==false ) {
            ret.first->second++;
        }
        int leader(-1000000001);
        for(map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) {
            if( it->second > (j+1)/2 ) {
                leader = it->first;
                break;
            }
        }
        B[i] = leader;
    }
    // for(unsigned int i=0; i<B.size(); ++i) {
        // cout << B[i] << endl;
    // }
    return B;
}

int solution(vector<int> &A) {
    // write your code in C++11
    vector<int> B = process(A,false);
    // cout << endl;
    vector<int> C = process(A,true);
    
    int count(0);
    for( unsigned int i=0; i<A.size()-1; ++i ) {
        if( B[i]==C[i+1] && B[i]>-1000000001 )
            count++;
    }
    
    return count;
}
