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
    
    int count(0);
    int j(-1);
    for(unsigned int i=0; i<A.size(); ++i) {
        if( A[i]==value ) {
            count++;
            j = i;
        }
    }
    if( count<=A.size()/2 )
        return -1;
    else
        return j;
}
