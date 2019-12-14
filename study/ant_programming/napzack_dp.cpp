#include <bits/stdc++.h>
using namespace std;

const int max_n = 100;
int n;
vector<pair<int, int>> wv;
int W;

void input(void){
    cin >> n >> W;
    for (int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;
        wv.emplace_back(make_pair(w, v));
    }
}

int rec(int i, int j) {
    int res;
    if(i == n) res = 0;
    else if(j < wv[i].first) res = rec(i + 1, j);
    else res = max(rec(i + 1, j), rec(i + 1, j - wv[i].first) + wv[i].second);

    return res;
}

void solve(void){
    cout << rec(0, W) << endl;
}

int main(void) {
    input();
    solve();

    return 0;
}