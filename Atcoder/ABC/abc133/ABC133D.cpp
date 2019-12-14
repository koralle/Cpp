#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Nは奇数
int N;
    cin >> N;
    vector<long long> arr_a(N, 0);
    for(int i = 0; i < N; i++){
        cin >> arr_a[i];
    }

    // 各山に降った雨の量
    vector<long long> rain_per_mount(N, 0);

    // 雨の合計量
    long long all_rain = 0;
    for(int i = 0; i < N; i++){
        all_rain += arr_a[i];
    }

    all_rain /= 2;


    for(int i = 0; i < N; i++){
        if(i == 0) rain_per_mount[N-1] = (all_rain - 2 * arr_a[i]) / 2;
        else rain_per_mount[i-1] = (all_rain - 2 * arr_a[i]) / 2;

    }

    for(int j = 0; j < N; j++){
        if(j == N-1) cout << rain_per_mount[j] << endl;
        else cout << rain_per_mount[j] << ' ';
    }

    return 0;
}
