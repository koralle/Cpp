#include <bits/stdc++.h>
using namespace std;

// Global Variables
int H, W;
vector<string> city(500);

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int sx, sy;
int gx, gy;

bool isVisited[500][500] = {false};

void input(void){
    cin >> H >> W;
    for (int hy = 0; hy < H; hy++){
        cin >> city[hy];
        for (int wx = 0; wx < W; wx++){
            if(city[hy][wx] == 's') {
                sx = wx;
                sy = hy;
            }
            if(city[hy][wx] == 'g') {
                gx = wx;
                gy = hy;
            }
        }
    }
}

void dfs(int y, int x){
    // 現在位置はとりあえず訪問済みにする
    isVisited[y][x] = true;

    // 上下左右の点を探索する
    for (int direction = 0; direction < 4; direction++){
        int n_hy = y + dy[direction];
        int n_wx = x + dx[direction];

        // 街の外には出ない
        if(n_hy < 0 || H <= n_hy || n_wx < 0 || W <= n_wx) continue;

        // 壁は越えられない
        if(city[n_hy][n_wx] == '#') continue;

        // 一度訪問した地点は通らない
        if(isVisited[n_hy][n_wx] == true) continue;

        dfs(n_hy, n_wx);
    }
    return;
}

void solve(void){
    dfs(sy, sx);

    if(isVisited[gy][gx] == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return;
}

int main(void){
    input();
    solve();

    return 0;
}