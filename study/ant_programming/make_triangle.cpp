#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr(N);
int ans = 0;

void make_input(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void solve(){
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int len = arr[i] + arr[j] + arr[k];
                int ma = max(arr[i], max(arr[j], arr[k]));
                int rest = len - ma;

                if(ma < rest)
                    ans = max(ans, len);
            }
        }
    }
}

int main(void) {
    make_input();
    solve();

    cout << ans << endl;
    return 0;
}