// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    // create an empty stack for alive fishes
    vector<int> C;
    unsigned int i(0);
    // go through all fishes to decide whether it is alive
    while( i<A.size() ) {
        // when stack is empty, current fish is always alive
        if( C.empty() ) {
            // current fish is alive, push back to the stack
            C.push_back(i);
            // update current fish to the next one
            i++;
        }
        else {
            // only when fish at top of the stack goes downstream
            // and current fish goes upstream, they can meet
            if( B[ C.back() ]==1 && B[i]==0 ) {
                // fish at top of the stack is smaller than current fish
                if( A[ C.back() ]<A[i] ) {
                    // fish at top of the stack is eaten by current fish, pop out of the stack
                    C.pop_back();
                    // when stack is empty, keep current fish and start over
                    if( C.empty() )
                        continue;
                }
                // fish at top of the stack is bigger than current fish
                else {
                    // fish at top of the stack eat current fish
                    // update current fish to the next one
                    i++;
                }
            }
            // fish at top of the stack never meet current fish
            // since they either go opposite ways or the same ways in the same speed
            else {
                // current fish is alive, push back to the stack
                C.push_back(i);
                // update current fish to the next one
                i++;
            }
        }
    }
    // all alive fishes remain in the stack 
    return C.size();
}
