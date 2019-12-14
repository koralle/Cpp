#include <bits/stdc++.h>
using namespace std;

int X, A, B;
int ans;
void input(void){
    cin >> X >> A >> B;
}

void solve(void){
    ans = X - (A + ((X - A) / B) * B);
    cout << ans << endl;
}

int main(void){
    input();
    solve();
    return 0;
}