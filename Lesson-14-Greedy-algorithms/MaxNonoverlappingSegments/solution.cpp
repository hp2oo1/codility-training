// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    vector<int> C;
    for( unsigned int i=0; i<A.size(); ++i ) {
        if( i==0 ) {
            C.push_back(B[i]);
        }
        else if( A[i]>C.back() ) {
            C.push_back(B[i]);
        }
    }
    return C.size();
}
