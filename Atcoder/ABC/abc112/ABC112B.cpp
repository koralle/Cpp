#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector< pair<int, int> > route(N);
    for(int i = 0; i < N; i++) {
    int c, t;
        cin >> c >> t;
        route[i] = make_pair(t, c);
    }

    // 時間が昇順になるようにソート
    sort(route.begin(), route.end());

    bool flag = false;
    int min_cost = 100000;
    for(int i = 0; i < N; i++){
        if (route[i].first > T) break;

        if(route[i].second <= min_cost){
            flag = true;
            min_cost = route[i].second;
        }
    }

    if (flag == true){
        cout << min_cost << endl;
    }
    else {
        cout << "TLE" << endl;
    }

    return 0;
}
