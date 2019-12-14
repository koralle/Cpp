#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long> > comb(long long n, long long r){
    vector<vector<long long> > v(n+1, vector<long long>(n+1, 0));

    for(long long i = 0; i < v.size(); i++){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for(long long j = 1; j < v.size(); j++){
        for(long long k = 1; k < j; k++){
            v[j][k] = (v[j-1][k-1] + v[j-1][k]);
        }
    }
    return v;
}

int main(){
    long long N, K;
    cin >> N >> K;

    vector<vector<long long> > ncr;
    ncr = comb(N, K);

    for(long long i = 1; i <= K; i++){
        cout << (ncr[N-K+1][i] * ncr[K-1][i-1]) % (1000000000+ 7) << endl;
    }

    return 0;
}
