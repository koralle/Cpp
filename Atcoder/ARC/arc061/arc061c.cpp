#include <bits/stdc++.h>
using namespace std;

// Global variables
string s;
int plus_operator[10] = {0};

void input(){
    cin >> s;
}

bool dfs(int pos, long long ans_sum){
    if(pos == s.length()) return 0;

    if(plus_operator[pos] == 0) return false;

    if(plus_operator[pos] == 1) {
        
    }

    return false;
}

void solve(){

}