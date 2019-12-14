#include <iostream>
#include <set>

using namespace std;

int main(){
    int N;
    int data[110];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> data[i];

    set<int> values;
    for (int i=0; i < N; i++) values.insert(data[i]);

    cout << values.size() << endl;
}
