#include <bits/stdc++.h>
using namespace std;

long long x;
long long y;
long long n3;
long long ans;

void input(){
    cin >> x >> y;
}

void solve(){
    if (x <= y) n3 = x / 3;
    else n3 = y / 3;

    long long tmp = pow(2, n3);

        

}

int main(void){
    input();
    solve();

    return 0;
}