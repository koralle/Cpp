#include <bits/stdc++.h>
using namespace std;

// Global variables
int W, H;
int fields[50][50];

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};

bool isVisited[50][50];

vector<int> output;

bool input(void){
    cin >> W >> H;
    if(W == 0 && H == 0) return false;

    for (int hy = 0; hy < H; hy++) {
        for (int wx = 0; wx < W; wx++) {
            fields[hy][wx] = 0;
            isVisited[hy][wx] = false;
            cin >> fields[hy][wx];
        }
    }

    return true;
}

void dfs(int hy, int wx) {
    isVisited[hy][wx] = true;


    for (int dir = 0; dir < 8; dir++) {
        int n_hy = hy + dy[dir];
        int n_wx = wx + dx[dir];

        // (n_wx. n_hy)は海域内の点か？
        if(n_hy < 0 || H <= n_hy || n_wx < 0 || W <= n_wx) continue;

        // (n_wx_, n_hy)島か？
        if(fields[n_hy][n_wx] == 0) continue;

        // (n_wx, n_hy)は到達済みか？
        if(isVisited[n_hy][n_wx] == true) continue;

        dfs(n_hy, n_wx);
    }

    return;
}

void solve(){
    int ans = 0;
    for (int hy = 0; hy < H; hy++){
        for (int wx = 0; wx < W; wx++) {
            if(fields[hy][wx] == 1 && isVisited[hy][wx] == false) {
                dfs(hy, wx);
                ans++;
            }
        }
    }

    output.emplace_back(ans);
}

int main(void){

    while(input() == true) solve();

    for (size_t i = 0; i < output.size() ; i ++) cout << output[i] << endl;

    return 0;
}