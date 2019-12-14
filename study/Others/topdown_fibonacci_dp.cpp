#include <iostream>
#include <vector>
using namespace std;

// トップダウン型アプローチでフィボナッチ数を求める
long long topdown_fibonacci_dp(vector<long long> &vx, const int n){

    // 既に計算済みならその値を返す
    if(vx[n] >= 0) return vx[n];

    // 初期値
    if(n == 0) vx[n] = 0;
    else if(n == 1) vx[n] = 1;

    // 部分問題を計算
    else vx[n] = topdown_fibonacci_dp(vx, n-1) + topdown_fibonacci_dp(vx, n-2);

    return vx[n];
}

int main(){
    int N;
    cin >> N;
    vector<long long> dp(N, -1);

    long long result = topdown_fibonacci_dp(dp, N-1);

    cout << result << endl;

    return 0;
}
