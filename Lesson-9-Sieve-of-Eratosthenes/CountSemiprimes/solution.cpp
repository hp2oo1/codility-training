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

int countSemiPrimes(vector<int> &semiPrimes, int first, int last) {
    int count(0);
    for(unsigned int i=0; i<semiPrimes.size(); ++i) {
        // cout << semiPrimes[i] << endl;
        if( semiPrimes[i]>=first && semiPrimes[i]<=last )
            count++;
    }
    return count;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++11
    int minP = findMin(P);
    int maxQ = findMax(Q);
    // cout << minP << " " << maxQ << endl;
    
    vector<int> primes = findPrimes(2,maxQ);
    // cout << endl;
    vector<int> semiPrimes = findSemiPrimes(primes,minP,maxQ);
    
    vector<int> counts(P.size(),0);
    for(unsigned int i=0; i<P.size(); ++i) {
        counts[i] = countSemiPrimes(semiPrimes,P[i],Q[i]);
    }
    
    return counts;
}
