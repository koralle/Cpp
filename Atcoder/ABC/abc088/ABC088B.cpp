#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int arr[110];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr+N, greater<int>());
    int Alice = 0;
    int Bob = 0;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) Alice += arr[i];
        else Bob += arr[i];
    }

    cout << Alice - Bob << endl;

    return 0;
}
