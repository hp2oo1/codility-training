// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int findMin(vector<int> &P) {
    int minP(P[0]);
    for(unsigned int i=0; i<P.size(); ++i) {
        if( P[i]<minP )
            minP = P[i];
    }
    return minP;
}

int findMax(vector<int> &Q) {
    int maxQ(Q[0]);
    for(unsigned int i=0; i<Q.size(); ++i) {
        if( Q[i]>maxQ )
            maxQ = Q[i];
    }
    return maxQ;
}

bool isPrime(int number) {
    int a = floor(sqrt(number));
    for(unsigned int i=a; i>1; --i) {
        if( number%i==0 )
            return false;
    }
    return true;
}

vector<int> findPrimes(int first, int last) {
    vector<int> primes;
    for(unsigned int i=first; i<=last; ++i) {
        if( isPrime(i) ) {
            primes.push_back(i);
            // cout << i << endl;
        }
    }
    return primes;
}

vector<int> findSemiPrimes(vector<int> &primes, int first, int last) {
    vector<int> semiPrimes;
    for(unsigned int i=0; i<primes.size(); ++i) {
        for(unsigned int j=0; j<primes.size(); ++j) {
            if( primes[i]<=primes[j] ) {
                int semiPrime = primes[i]*primes[j];
                if( semiPrime>=first && semiPrime<=last ) {
                    semiPrimes.push_back( semiPrime );
                    // cout << semiPrime << endl;
                }
            }
        }
    }
    return semiPrimes;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {

    if( N==1 ) {
        return vector<int>(1,0);
    }

    // write your code in C++11
    int minP = findMin(P);
    int maxQ = findMax(Q);
    // cout << minP << " " << maxQ << endl;
    
    vector<int> primes = findPrimes(2,maxQ);
    // cout << endl;
    vector<int> semiPrimes = findSemiPrimes(primes,minP,maxQ);
    sort(semiPrimes.begin(),semiPrimes.end());

    // cout << endl;

    // after
    vector<int> A(N,0);
    int count(0);
    int j(semiPrimes.size()-1);
    for(unsigned int i=0; i<N; ++i) {
        int k = N-1-i;
        if( k+1 < semiPrimes[j] ) {
            count++;
            j--;
            if( j==0 )
                j= 0;
        }
        // cout << k+1 << " " << count << endl;
        A[k] = count;
    }
    
    // cout << endl;
    
    // before
    vector<int> B(N,0);
    count=0;
    j=0;
    for(unsigned int i=0; i<N; ++i) {
        int k=i;
        if( k+1 > semiPrimes[j] ) {
            count++;
            j++;
            if( j==0 )
                j= 0;
        }
        // cout << k+1 << " " << count << endl;
        B[k] = count;
    }
    
    int total = semiPrimes.size();
    
    vector<int> counts(P.size(),0);
    for(unsigned int i=0; i<P.size(); ++i) {
        // cout << total << " " << A[Q[i]-1] << " " << B[P[i]-1] << endl;
        counts[i] = total - A[Q[i]-1] - B[P[i]-1];
    }
    
    return counts;
}
