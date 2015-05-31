// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    vector<int> C;
    unsigned int i(0);
    while( i<A.size() ) {
        if( C.empty() ) {
            C.push_back(i);
            i++;
        }
        else {
            if( B[ C[C.size()-1] ]==1 && B[i]==0 ) {
                if( A[ C[C.size()-1] ]<A[i] ) {
                    C.pop_back();
                    if( C.empty() )
                        continue;
                }
                else {
                    i++;
                }
            }
            else {
                C.push_back(i);
                i++;
            }
        }
    }
    return C.size();
}
