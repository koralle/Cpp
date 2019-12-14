#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long N;
    long long K;
    cin >> N >> K;
    vector<long long> arrS(N);
    for (long long i = 0; i < N; ++i) cin >> arrS[i];


    long long right = 0;
    long long cnt = 0;
    long long sum_ = 0;
    for(long long left = 0; left < N; ++left){
        while(right < N && sum_ + arrS[right] < K){
            sum_ += arrS[right];
            ++right;

        }
        cnt += (right - left);

    if(left == right) ++right;
        else sum_ -= arrS[left];
    }

    long long cnt_ = (N * (N+1)) / 2;

    cout << cnt_ - cnt << endl;

    return 0;
}
