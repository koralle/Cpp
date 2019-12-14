#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;

    if(N % 2 == 0) cout << setprecision(10) << 1 / (double)2 << endl;
    else cout << setprecision(10) << ((N + 1) / (double)2) / (double)N << endl;

    return 0;
}