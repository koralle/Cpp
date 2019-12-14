#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

// DP用テンプレート
template<class T> inline bool chmax(T& a, T b){
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T& a, T b){
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

// 無限大
const long long INF 1LL << 60;

// DPデーブル
long long dp[100010];

// DPテーブル全体を初期化
for(int i = 0; i < 100010; ++i) dp[i] = INF;

// 初期条件
dp[0] = 0;

int main(){
    int N;
    cin >> N;
    for(int i = 1; i < N; i++){
        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if(i > 1) chmin(dp[i], dp[i-1] + abs(h[i] - h[i-2]));
    }
    cout << dp[N-1] << endl;

    return 0;
}
