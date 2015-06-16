// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    
    // special case
    if(A.empty()) return -1;
    
    // compute sum for all
    long sum(0);
    for(unsigned int i=0; i<A.size(); ++i) {
        sum += A[i];
    }

    // special cases
    if( sum-A[0]==0 ) return 0;
    if( sum-A.back()==0 ) return A.size()-1;

    // process
    long sumL(0), sumR(0);
    for(unsigned int i=1; i<A.size()-1; ++i) {
        sumL += A[i-1];
        sumR = sum - sumL - A[i];
        if( sumL == sumR )
            return i;
    }
    return -1;
}
