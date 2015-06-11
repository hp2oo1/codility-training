// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    int count(0);
    int BB;
    for( unsigned int i=0; i<A.size(); ++i ) {
        if( i==0 ) {
            count++;
            BB = B[i];
        }
        else if( A[i]>BB ) {
            count++;
            BB = B[i];
        }
    }
    return count;
}
