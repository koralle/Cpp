#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arrP(n);
    for(int i = 0; i < n; i++) cin >> arrP[i];

    int cnt = 0;
    for(int i = 1; i < n-1; i++) {
        if((arrP[i] >= arrP[i-1]) && (arrP[i]) <= arrP[i+1]) cnt++;
        else if((arrP[i] <= arrP[i-1]) && (arrP[i]) >= arrP[i+1]) cnt++;
    }

    cout << cnt << endl;
    return 0;
}
