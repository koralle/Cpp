#include <bits/stdc++.h>
using namespace std;

int main(void){

    long long N, K;
    cin >> N >> K;
    vector<long long> height(N);
    for(long long i = 0; i < N; i++) cin >> height[i];

    long long cnt = 0;
    for(long long j = 0; j < N; j++) {
        if(height[j] >= K) cnt++;
    }

    cout << cnt << endl;

    return 0;
}