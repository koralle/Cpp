#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> sticks(N);
    for(int i = 0; i < N; i++) cin >> sticks[i];

    sort(sticks.begin(), sticks.end(), greater<int>());

    int max_snake_length = 0;
    for(int i = 0; i < K; i++) max_snake_length += sticks[i];

    cout << max_snake_length << endl;

    return 0;
}
