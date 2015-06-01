// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void process(vector<int> &A, int first, int last, long &max, int &max_i, bool reverse) {
    long sum(0);
    for(unsigned int j=first; j<=last; ++j) {
        int i = j;
        if( reverse )
            i = last-first-j;
        sum += A[i];
        if( sum>max ) {
            max = sum;
            max_i = i;
        }
    }
}

int solution(vector<int> &A) {
    // write your code in C++11
    // 0-->q in [0,N-1]
    long max_1(A[0]);
    int max_q(0);
    process( A, 0, A.size()-1, max_1, max_q, false );
    // cout << max_q << " " << max_1 << endl;

    // p<--N-1 in [0,N-1]
    long max_2(A.back());
    int max_p(A.size()-1);
    process( A, 0, A.size()-1, max_2, max_p, true );
    // cout << max_p << " " << max_2 << endl;

    long max;
    if( max_1 > max_2 ) {
        // p<--q in [0,max_q]
        max = A[max_q];
        int max_p(max_q);
        process( A, 0, max_q, max, max_p, true );
        // cout << max_p << " " << max << endl;
    }
    else {
        // p-->q in [max_p,N-1]
        max = A[max_p];
        int max_q(max_p);
        process( A, max_p, A.size()-1, max, max_q, false );
        // cout << max_q << " " << max << endl;
    }

    return max;
}
