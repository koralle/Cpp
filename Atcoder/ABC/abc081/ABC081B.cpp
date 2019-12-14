#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arrInteger(n);
    for(int i = 0; i < n; i++) cin >> arrInteger[i];

    int max_cnt = 0;
    bool flag = false;
    while(true){
    for(int i = 0; i < n; i++){
            if (arrInteger[i] % 2 == 1){
                flag = false;
                break;
            }
            arrInteger[i] /= 2;
            flag = true;
        }
        if(flag == false) break;

        max_cnt++;
    }

    cout << max_cnt << endl;

    return 0;
}
