#include<bits/stdc++.h>
using namespace std;

// Global Variables
long long N, Y;

void input(void){
    cin >> N >> Y;
}

void solve(void){
    long long x = -1, y = -1, z = -1;
    for (long long  i = 0; i <= N; i++){
        for (long long j = 0; j <= N - i; j++) {
            long long k = N - (i + j);
            long long otoshidama = i * 10000 + j * 5000 + k * 1000;
            if(otoshidama == Y) {
                x = i; y = j; z = k;
            }
            else { /* Do nothing */  }
        }
    }

    cout << x << " " << y << " " << z << endl;
}

int main(void) {
    input();
    solve();

    return 0;
}