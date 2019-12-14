#include <bits/stdc++.h>
using namespace std;

int N;
string s;

void input(void){
    cin >> N;
    cin >> s;
}

void solve(void){
    if (N % 2 == 1) {
        cout << "No" << endl;
        return;
    }


    int n = N / 2;
    if (s.substr(0, n) == s.substr(n,n)) {
        cout << "Yes" << endl;
        return;
    }
    else {
        cout << "No" << endl;
        return;
    }

}

int main(void){
    input();
    solve();
    return 0;
}