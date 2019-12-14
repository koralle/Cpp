#include <bits/stdc++.h>
using namespace std;

// global variables
int N;
vector<int> arr;
int ans = 0;

void input(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        arr.emplace_back(a);
    }
}

void solve(void){
    for(int i = 0; i < N; i++) ans += (arr[i] -1);
    cout << ans << endl;
}

int main(void){

    input();
    solve();

    return 0;
}