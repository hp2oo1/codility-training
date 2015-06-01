// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    int price_min(200001);
    int profit_max(-1);
    for(unsigned int i=0; i<A.size(); ++i) {
        if( A[i]<price_min )
            price_min = A[i];
        int profit = A[i] - price_min;
        if( profit > profit_max )
            profit_max = profit;
    }
    return profit_max;
}
