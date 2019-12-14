#include <bits/stdc++.h>
using namespace std;

int N;
int candies[2][100] = {0};
int total_candies = 0;
int ans = 0;

// {右, 下, 左上, 右下}への移動を表すベクトル
int dx[4] = {1, 0, -1, 1};
int dy[4] = {0, 1, -1. 1};

int next_x;
int next_y;

// 訪問済みかどうか
bool isVisited[2][100] = {false};

void input(void){
    cin >> N;
    for (int hy = 0; hy < 2; hy++){
        for (int wx = 0; wx < N; wx++) {
            cin >> candies[hy][wx];
            total_candies += candies[hy][wx];
        }
    }
}

void search_candies(int y, int x){

    ans += candies[y][x];
    isVisited[y][x] = true;

    if(isVisited[1][N-1] == true) return;

    int tmp = 0;
    for (int dir = 0; dir < 4; dir++){
        int n_hy = y + dy[dir];
        int n_wx = x + dx[dir];

        if(n_hy < 0 || 1 < n_hy || n_wx < 0 || N <= n_wx) continue;

        if(isVisited[n_hy][n_wx] == true) continue;

        if(candies[n_hy][n_wx] < tmp) continue;

        
    }

        return;
}

void solve(void){
    // Nが奇数だったら全ての飴の総数を出す。
    if( N % 2 == 0) {
        cout << total_candies << endl;
        return;
    }

    search_candies(0, 0);
    return;
}

int main(void){
    input();
    solve();

    return 0;
}