#include <bits/stdc++.h>
using namespace std;

int main(void){
    string move_pos;
    cin >> move_pos;

    // 奇数
    for (unsigned int i = 0; i < move_pos.length(); i+=2){
        // 偶数
        if(move_pos[i] == 'L') {
            cout << "No" << endl;
            return 0;
        }
        for (unsigned int j = 1; j < move_pos.length(); j+=2){
            if (move_pos[j] == 'R') {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}