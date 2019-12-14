#include <iostream>
#include <vector>
using namespace std;


int abs(int num);

int main(){
    int N, L;
    cin >> N >> L;

    int taste_sum = 0;
vector<int> apple(N);
    int min_abs = 10000;

    // 食べるリンゴを選ぶ
    for(int i = 1; i <= N; i++){
        int taste = abs(L + i - 1);
        if(taste < min_abs) min_abs = taste;
    }

    // N-1このリンゴの「味」の総和を求める
    for(int i = 1; i <= N; i++){
        if(abs(L + i - 1) == min_abs) continue;
        taste_sum += L + i - 1;
    }

    cout << taste_sum << endl;
}

int abs(int num) {
    if (num < 0) return -num;
    return num;
}
