#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

        int N, M;
        cin >> N >> M;

        vector<int> arrL(M, 0);
        vector<int> arrR(M, 0);
        for(int i = 0; i < M; i++) cin >> arrL[i] >> arrR[i];

        sort(arrL.begin(), arrL.end());
        sort(arrR.begin(), arrR.end());

        int cnt = 0;
        for(int j = 1; j <= N; j++){
            if(j >= arrL[M-1] && j <= arrR[0] ) cnt++;
        }

        cout << cnt << endl;
    return 0;
}
