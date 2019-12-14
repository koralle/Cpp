#include <bits/stdc++.h>
using namespace std;

string s;
string t;
bool ans = false;

void do_input(void){
    cin >> s;
    cin >> t;
}

void solve(void){
    for (unsigned int i = 0; i < s.size(); i++){
        s = s.back() + s.substr(0, s.size() -1);
        if(s == t) {
            ans = true;
            break;
        }
    }

    if(ans == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}


int main(void){
    do_input();

    solve();
    return 0;
}