#include <bits/stdc++.h>
using namespace std;

// Global variables
const int INF = 100000000;

typedef pair<int, int> pos;

char maze[100][100 + 1];
int N, M;
int start_x, start_y; // スタート地点の座標
int goal_x, goal_y;   // ゴール地点の座標

int dis[100][100];

// 4方向のベクトルの組
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input(void) {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            maze[i][j] = s[j];
            if(maze[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
            if(maze[i][j] == 'G') {
                goal_x = i;
                goal_y = j;
            }
        }
    }
}

// スタート地点(start_x, start_y)
// => ゴール地点(goal_x, goal_y)までの最短距離を求める
int bfs(void) {
    
    // 幅優先探索を使えば最短経路や最短手数が簡単に計算できる。
    // 幅有線探索を使うときは次のステップを踏む。
    // 1. キューを定義する。
    // 2. 初期状態をキューに入れる。
    //    キューから状態を取り出す。
    // 3. そこから遷移できるが、まだ遷移したことがない状態をキューに入れる。
    // 4. 2-3をキューが空になるor解が見つかるまで繰り返す。
    queue<pos> que;
    // まずは全ての点における最短距離をINFに初期化する
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) dis[i][j] = INF;
    }
    // スタート地点(start_x, start_y)をqueに突っ込む
    que.push(pos(start_x, start_y));
    // その点における最短距離を0にする。
    dis[start_x][start_y] = 0;

    // キューが空になるまでループする。
    while(que.size()){
        // キューの先頭を取り出す 
        pos p = que.front();
        que.pop();
        // 取り出してきた状態がゴールなら探索を辞める
        if(p.first == goal_x && p.second == goal_y) break;

        // 取り出してきた位置を基準に4方向ループする。
        for (int i = 0; i < 4; i++){
            // 移動した後の点を(nx, ny)とする。
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            // 位置(nx, ny)へ移動可能であるか?
            if(0 <= nx && nx < N && 0 <= ny && ny < M) {
                // 既に訪れた場所か?
                if(maze[nx][ny] != '#' && dis[nx][ny] == INF) {
                    // まだ訪れてないけど移動できるのならばその位置をキューに入れ、
                    // その点までの最短距離を+1する。
                    que.push(pos(nx, ny));
                    dis[nx][ny] = dis[p.first][p.second] + 1;
                }
            }
        }
    }
    return dis[goal_x][goal_y];
}

void solve(){
    int res = bfs();
    cout << res << endl;
}

int main(void) {
    input();
    solve();
    return 0;
}