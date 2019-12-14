#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, X;
    cin >> N >> X;
    vector<int> arrL(N);
    for (int i = 0; i < N; i++) cin >> arrL[i];

    int d = 0;
    int cnt = 1;
    for(int j = 0; j < N; j++){
        d += arrL[j];
        if (d > X) break;

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
