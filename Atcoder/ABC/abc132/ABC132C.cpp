#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> arr_d(N, 0);
    for(int i = 0; i < N; i++) cin >> arr_d[i];

    // 昇順にソート
    sort(arr_d.begin(), arr_d.end());

    // 問題数をABCとARCで同じにする
    int num_q = N / 2;

    // arr_d[num_q-1]より大きくarr_d[num_q]以下の整数の数 = K
    int K = arr_d[num_q] - arr_d[num_q-1];

    cout << K << endl;

    return 0;
}
