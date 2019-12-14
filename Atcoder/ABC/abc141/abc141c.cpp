#include <bits/stdc++.h>
using namespace std;

int main(void){

    long long N, K, Q;
    cin >> N >> K >> Q;
    vector<long long> arr(Q);
    for (long long i = 0; i < Q; i++) cin >> arr[i];

    vector<long long> point(N, 0);

    for (long long i = 0; i < Q; i++) point[arr[i]-1]++;

    for (long long i = 0; i < N; i++) {
        if(Q - point[i] >= K) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}