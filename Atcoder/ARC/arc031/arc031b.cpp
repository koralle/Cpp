#include <bits/stdc++.h>
using namespace std;

// Global Variables
vector<string> field(10);

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool isVisited[10][10] = {false};
bool flag = false;

void input(void){
    for (int i = 0; i < 10; i++) {
        cin >> field[i];
    }
}

void dfs(int y, int x){

    isVisited[y][x] = true;

    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            int nx = x + dx;
            int ny = y + dy;

            if(ny < 0 || 10 <= ny || nx < 0 || 10 <= nx) continue;
            if(field[y][x] == 'x') continue;
            if(isVisited[y][x] == true) continue;

            dfs(ny, nx);
        }
    }
}

bool check(int start_y, int start_x){
    dfs(start_y, start_x);
    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j++){
            if(field[i][j] == 'o' && isVisited[i][j] == false) return false;
        }
    }

    return true;
}

void solve(void){
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j ++){
            if(check(i, j)) flag = true;
        }
    }

    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}


int main(void) {
    input();
    solve();

    return 0;
}