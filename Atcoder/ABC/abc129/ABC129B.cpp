#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int>weight(N);
    for (int i = 0; i < N; i++) cin >> weight[i];

    vector<int>cul_sum(N+1, 0);
    for (int i = 0; i < N; i++) cul_sum[i+1] = (cul_sum[i] + weight[i]);

    int min_abs = 10000000; //
    for(int j = 1;j < N; j++){
        int tmp = abs(cul_sum[N] - 2 * cul_sum[j]);

        if (tmp <= min_abs) min_abs = tmp;
    }

    cout << min_abs << endl;
    return 0;
}
