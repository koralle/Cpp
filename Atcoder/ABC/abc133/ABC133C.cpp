#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long L, R;
    cin >> L >> R;

long long mod_min = 1000000000;
    for(long long i = L; i < R; i++){
        for(long long j = i+1; j <= R; j++){
            long long tmp = (i * j) % 2019;
            if (tmp <= mod_min) mod_min = tmp;
        }
    }
    cout << mod_min << endl;

    return 0;
}
