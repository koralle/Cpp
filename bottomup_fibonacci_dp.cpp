#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> dp(N, -1);

    // ボトムアップ型アプローチでフィボナッチ数を求める
    for(int n = 0; n < N; n++){
        if(n == 0) dp[n] = 0;
        else if(n == 1) dp[n] = 1;
        else dp[n] = dp[n-1] + dp[n-2];
    }

    cout << dp[N-1] << endl;

    return 0;
}
