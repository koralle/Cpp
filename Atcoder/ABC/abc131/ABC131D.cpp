#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


int main(){
    int n;
    vector<pair<int, int> > tasks;

    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        tasks.emplace_back(b, a); //(〆切, 所要時間)
    }

    // 〆切の早い順にソートする
    sort(tasks.begin(), tasks.end());
    int sum = 0;
    bool isyes = true;
    for(auto v: tasks){
        sum += v.second;

        if(sum > v.first){
            isyes = false;
            break;
        }
    }

    cout << (isyes ? "Yes" : "No") << endl;

    return 0;
}
