#include <iostream>
using namespace std;

long long gcd(long long a, long long b);
long long abc131c(long long n, long long nc, long long nd);

long long abc131c(long long n, long long nc, long long nd){
    long long n_nc, n_nd, n_gcd, n_ncnd;

// Cで割り切れる数の個数
    n_nc = n / nc;

    // Dで割り切れる数の個数
    n_nd = n / nd;

    // CでもDでも割り切れる数の個数
    n_gcd = nc * nd / gcd(nc, nd);
    n_ncnd = n / n_gcd;

    return n - n_nc - n_nd + n_ncnd;
}

long long gcd(long long a, long long b){
    if(a < b) {
        long long tmp = b;
        b = a;
        a = tmp;
    }

    long long r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long num1 = abc131c(b, c, d);
    long long num2 = abc131c(a-1, c, d);

    cout << num1 - num2 << endl;

    return 0;
}
