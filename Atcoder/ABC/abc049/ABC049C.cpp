#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main(){
    string S;
    cin >> S;

    // 後ろから説く代わりにすべての文字列を「左右反転」する
    reverse(S.begin(), S.end());
    for(int i = 0; i < 4; ++i) reverse(divide[i].begin(), divide[i].end());

    // 端から切っていく
    bool can = true;
    for(int i = 0; i < S.size();){
        bool can2 = false; // 4この文字列のうちどれかでdevideできるか
        for(int j = 0; j < 4; ++j){
            string d = divide[i];
            if(S.substr(i, d.size()) == d){ // dでdivideできるか
                can2 = true;
                i += d.size(); // divideできたらiを進める
            }
        }
        if(!can2){ // divideできなかったら
            can = false;
            break;
        }
    }

    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
