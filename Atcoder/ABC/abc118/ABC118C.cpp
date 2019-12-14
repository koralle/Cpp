#include <iostream>
#include <vector>

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
    vector<long> arr(N);
    for(int i = 0; i < N; i++) cin >> arr[i];

    vector<long> arr_gcd(N+1, 0);

    for(int j = 0; j < N; j++) arr_gcd[i+1] = gcd(arr_gcd[i], arr[i]);
}
