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
