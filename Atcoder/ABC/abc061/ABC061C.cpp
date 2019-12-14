#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int N;
    long K;
    cin >> N >> K;

    vector<pair<int, int> > insert_arr(N);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        insert_arr[i] = make_pair(a, b);
    }

    sort(insert_arr.begin(), insert_arr.end());

    long second_sum = 0;
    int result = 0;
    for(int i = 0; i < N; i++){
        if(second_sum + (long)insert_arr[i].second >= K){
             result = insert_arr[i].first;
             break;
         }
         second_sum += (long)insert_arr[i].second;
    }
    cout << result << endl;
    return 0;
}
