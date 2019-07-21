#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &v, int n);

// 挿入ソート(昇順)
// 例: [4, 3, 9, 1, 2] => [1, 2, 3, 4, 9]
void insertion_sort(vector<int> &v, int n){
    // v[i]をソート済みの列v[0..i-1]に追加する
    for(int i = 1; i < n; i++){
        // 挿入したい値を保存
        int key = v[i];

        // v[i-1] からv[0]までさかのぼる
        int j = i-1;
        while(j >= 0) {
            // さかのぼる途中で挿入する位置が確定
            if(v[j] <= key) break;

            // v[j]を一つ後ろにずらす
            v[j+1] = v[j];
            j--;
        }
        // 値を挿入
        v[j+1] = key;
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> vx(N, 0);
    for(int i = 0; i < N; i++) cin >> vx[i];

    insertion_sort(vx, N);
    for(int i = 0; i< N; i++) cout << "vx[" << i << "] = " << vx[i] << endl;

    return 0;
}