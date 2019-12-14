#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    set<int> values;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        values.insert(arr[i]);
    }

    int backet_size = 200010;
    vector<int> backet(backet_size);
    for(int i = 0; i < N; i++) backet[arr[i]]++;
    sort(backet.begin(), backet.end(), greater<int>());


    int balls = 0;
    for (int i = 0; i < K;i++){
        balls += backet[i];
    }

    cout << N - balls << endl;

}
