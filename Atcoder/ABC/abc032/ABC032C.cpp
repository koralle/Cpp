#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> arrS(N);
    for (int i = 0; i < N; ++i) cin >> arrS[i];

    for(int i = 0; i < N; ++i){
        if(arrS[i] == 0){
            cout << N << endl;
            return 0;
        }
    }

    int max_res = 0;
    int right = 0;
    long long mul = 1;
    for(int left = 0; left < N; ++left){
        while(right < N && mul * arrS[right] <= K){
            mul *= arrS[right];
            ++right;
        }

        max_res = max(max_res, right - left);

        if(left == right) ++right;
        else mul /= arrS[left];
    }

    cout << max_res << endl;

    return 0;
}
