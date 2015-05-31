// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // write your code in C++11
    vector<int> stack;
    int count(0);
    for(unsigned int i=0; i<H.size(); ++i) {
        while( !stack.empty() && stack.back()>H[i] ) {
            stack.pop_back();
        }
        if( stack.empty() || stack.back()<H[i] ) {
            stack.push_back( H[i] );
            count++;
        }
    }
    return count;
}
