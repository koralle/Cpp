#include <bits/stdc++.h>
using namespace std;

// Global Variables
int N, M;
char field[100][101];

void input(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) field[i][j] = tmp[j];
    }
}

void dfs(int x, int y){
    // 現在位置の'W'を'.'に置換する
    field[x][y] = '.';

    // 現在位置から8方向に移動できるので全方向を1マスずつ進んで探索する
    for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;

            // 1マス進んだ先が以下の全ての条件に当てはまるかどうか判定する。
            // 1. 庭の範囲内かどうか
            // 2. 1マス進んだ位置(nx, ny)が水溜まりかどうか
            // 条件を満たしたらそのマスに移動して再帰
            if((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
                if(field[nx][ny] == 'W') return dfs(nx, ny);
            }
        }
    }
    return;
}

void solve(void){
    int res = 0;
    // 'W'がなくなるまで普通に全探索する
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(field[i][j] == 'W') {
                // 'W'を発見したらその位置を起点にdfsを始める
                // その起点からつながっている'W'は
                //まとめて1つの水溜まりとカウントするので
                // 起点にした'W'の数をただ答えにすればいい
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
}

int main(void) {
    input();
    solve();

    return 0;
}