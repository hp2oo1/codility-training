// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // write your code in C++11
    int count(0);
    int sum(0);
    for(unsigned int i=0; i<A.size(); ++i) {
        sum += A[i];
        if( sum>=K ) {
            count++;
            sum=0;
        }
    }
    return count;
}
