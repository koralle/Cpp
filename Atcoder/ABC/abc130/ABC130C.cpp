#include <iostream>
using namespace std;

int main(){

    long long W, H, x, y;
    cin >> W >> H >> x >> y;

    cout << W * H / 2 << ' ';
    if(x == W / 2 && y == H / 2){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}
