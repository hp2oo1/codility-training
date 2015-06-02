// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int process(int mid, vector<int> &A) {
    int k(1);
    int sum(0);
    for(unsigned int i=0; i<A.size(); ++i) {
        sum += A[i];
        if( sum>mid ) {
            sum = A[i];
            k++;
        }
    }
    return k;
}

int solution(int K, int M, vector<int> &A) {
    // write your code in C++11
    int lower_bound(A[0]);
    int upper_bound(0);
    for(unsigned int i=0; i<A.size(); ++i) {
        lower_bound  = max(lower_bound,A[i]);
        upper_bound += A[i];
    }
    
    int result(-1);
    while( lower_bound<=upper_bound ) {
        int mid = (lower_bound + upper_bound) / 2;
        cout << lower_bound << " " << mid << " " << upper_bound;
        int k = process(mid,A);
        if( k<=K ) {
            upper_bound = mid-1;
            result = mid;
        }
        else {
            lower_bound = mid+1;
        }
        // cout << " " << k << " " << result << endl;
    }
    return result;
}
