#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int bottom_up_cut_rod(vector<int> &vx, const int n);

// ボトムアップ型DP, 最悪計算量O(N)
// e.g. vx = [1, 5, 8, 8, 9, 10, 17, 17, 20, 24, 30], n = 10
// -> return 30
int bottom_up_cut_rod(vector<int> &vx, const int n){
    // 計算結果保存用配列
    vector<int> vr(n+1, 0);

    // vr[1..n]に計算結果を保存するためのforループ
    for(int j = 1; j <= n; j++){
        int q = -1000000;

        // vx[0..j-1]における部分問題を計算
        for(int i = 0; i < j; i++) q = max(q, vx[i] + vr[j-(i+1)]);

        // 計算結果を保存
        vr[j] = q;
    }
    return vr[n];
}

int main(){

    int N;
    cin >> N;
    vector<int> vx(N, 0);
    for(int i = 0; i < N; i++) cin >> vx[i];

    cout << bottom_up_cut_rod(vx, N) << endl;

    return 0;
}
