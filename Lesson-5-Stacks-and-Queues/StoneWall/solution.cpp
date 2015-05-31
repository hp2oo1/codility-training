// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // write your code in C++11
    vector<int> stack;
    int count(0);
    unsigned int i(0);
    while( i<H.size() ) {
        if( stack.empty() ) {
            stack.push_back( H[i] );
            count++;
            i++;
        }
        else {
            while( !stack.empty() && stack.back()>H[i] ) {
                stack.pop_back();
            }
            if( stack.empty() )
                continue;
            else if( stack.back()==H[i] ) {
                i++;
            }
            else if( stack.back()<H[i] ) {
                stack.push_back( H[i] );
                count++;
                i++;
            }
        }
    }
    return count;
}
