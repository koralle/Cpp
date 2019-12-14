#include <bits/stdc++.h>
using namespace std;

// Global variables
long long N;
vector<long long> arr;
long long k;

void input(void) {
    cin >> N;
    for (long long i = 0; i < N; i++) {
        long long a;
        cin >> a;
        arr.emplace_back(a);
    }
    cin >> k;
}

bool search(long long i, long long sum) {
    // n個に対して探索終了後、それまでの総和sumがkに等しいか判定する。
    if(i == N) return sum == k;

    // arr[i]は部分和に採用しない場合
    // →(i+1)個まで探索した結果がtrueなら同様にtrueを返せばok
    if(search(i + 1, sum) == true) return true;

    // arr[i]は部分和に採用する場合
    // →(i+1)個まで探索した結果がtrueなら同様にtrueを返せばok
    if (search(i + 1, sum) == true) return true;

    // arr[i]を使うかどうかにかかわらず、
    // (i+1)個まで探索した結果がfalseなら同様にfalseを返せばok
    return false;
}

void solve(void) {
    if(search(0, k) == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(void) {
    input();
    solve();

    return 0;
}