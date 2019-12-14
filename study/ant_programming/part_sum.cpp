#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

void input(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a.emplace_back(b);
    }
}

// iまでsumを作って、、残りi以降を調べる
bool dfs(int i, int sum) {
    // n個決め終わったら、今までの和sumがkと等しいかを返す
    if (i == n) return sum == k;

    // a[i]を使わない場合
    if(dfs(i+1, sum)) return true;

    // a[i]を使う場合
    if(dfs(i+1, sum+a[i])) return true;

    // a[i]を使う使わないにかかわらずkが作れないのでfalseを返す
    return false;
}

void solve(void) {
    if(dfs(0, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(void){
    input();
    solve();
    return 0;
}