#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 long gcd(long a,  long b){
    if(a < b) {
        long tmp = b;
        b = a;
        a = tmp;
    }

    long r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){

    int N;
    long X;
    cin >> N >> X;
    vector<long> city(N+1);
    city[0] = X;
    for(int i = 1; i <= N; i++) cin >> city[i];

    // (N+1)個の座標を昇順に並べる
    sort(city.begin(), city.end());

    // (N+1)個の座標の距離を記録する
    vector<long> distance(N+1, 0);
    for(int i = 1; i <= N; i++) distance[i] = city[i] - city[i-1];


    vector<long> d_gcd(N+1, 0);
    for(int i = 1; i <= N; i++){
        if(i == 1) d_gcd[i] = distance[i];
        else d_gcd[i] = gcd(d_gcd[i-1], distance[i]);
    }

    cout << d_gcd[N] << endl;

    return 0;
}
