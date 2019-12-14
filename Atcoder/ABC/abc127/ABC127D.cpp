#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector< pair<long long, int> > arrA(N);
    for(int i = 0; i < N; i++){
        long long tmp;
        cin >> tmp;
        arrA[i] = make_pair(tmp, 1);
    }

    vector<pair<long long, int> > arrBC(M);
    for(int i = 0; i < M; i++){
        int B = 0;
        long long C = 0;
        cin >> B >> C;
        arrBC[i] = make_pair(C, B);
    }

    // arrAの末尾にarrBCを連結
    arrA.insert(arrA.end(), arrBC.begin(), arrBC.end());
    sort(arrA.begin(), arrA.end(), greater<pair<long long, int> >());

    int cnt = 0;
    long long result = 0;
    int idx = 0;
    while(idx <= N+M-1){
        if(cnt + arrA[idx].second > N){
            result += ((N - cnt) * arrA[idx].first);
            break;
        }
        result += (arrA[idx].second * arrA[idx].first);
        cnt += arrA[idx].second;
        idx++;
    }

    cout << result << endl;
    return 0;
}
