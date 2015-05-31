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

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    
    int size(0);
    int value(0);
    for(unsigned int i=0; i<A.size(); ++i) {
        if( size==0 ) {
            size++;
            value = A[i];
        }
        else {
            if( A[i]==value )
                size++;    
            else
                size--;
        }
    }
    if( size<=0 )
        return 0;
        
    int count(0);
    for(unsigned int i=0; i<A.size(); ++i) {
        if( A[i]==value )
            count++;
    }
    if( count<=A.size()/2 )
        return 0;
    
    int number(0);
    int total(count);
    for(unsigned int i=0; i<A.size(); ++i) {
        if( A[i]==value )
            count--;
        if( (total-count)>(i+1)/2 && count>(A.size()-(i+1))/2 )
            number++;
    }
    return number;
}
