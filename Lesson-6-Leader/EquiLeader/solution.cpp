// you can use includes, for example:
// #include <algorithm>
#include <map>
#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> process(vector<int> &A, bool reverse) {
    vector<int> B(A.size(),0);
    map<int,int> mymap;
    for(unsigned int j=0; j<A.size(); ++j) {
        unsigned int i=j;
        if( reverse ) {
            i = A.size()-1-j;
        }
        pair<map<int,int>::iterator,bool> ret;
        ret = mymap.insert( make_pair(A[i],1) );
        if( ret.second==false ) {
            ret.first->second++;
        }
        int leader(-1000000001);
        for(map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) {
            if( it->second > (j+1)/2 ) {
                leader = it->first;
                break;
            }
        }
        B[i] = leader;
    }
    // for(unsigned int i=0; i<B.size(); ++i) {
        // cout << B[i] << endl;
    // }
    return B;
}

int solution(vector<int> &A) {
    // write your code in C++11
    vector<int> B = process(A,false);
    // cout << endl;
    vector<int> C = process(A,true);
    
    int count(0);
    for( unsigned int i=0; i<A.size()-1; ++i ) {
        if( B[i]==C[i+1] && B[i]>-1000000001 )
            count++;
    }
    
    return count;
}
