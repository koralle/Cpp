#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int memolized_cut_rod(const vector<int> &v, const int n);
int memolized_cut_rod_aux(const vector<int> &v, const int n, vector<int> &r);

int memolized_cut_rod(const vector<int> &v, const int n){
    vector<int> r(n+1, -1000000);
    return memolized_cut_rod_aux(v, n, r);
}

int memolized_cut_rod_aux(const vector<int> &v, const int n, vector<int> &r){
    int q = 0;
    if(r[n] >= 0) return r[n];
    if (n == 0) {
        q = 0;
    }
    else{
        q = -1000000;
        for(int i = 0; i < n; i++){
            q = max(q, v[i] + memolized_cut_rod_aux(v, n-(i+1), r));
        }
    }
    r[n] = q;
    return q;
}


int main(){

    int N;
    cin >> N;
    vector<int> v(N, 0);
    for(int i = 0; i < N; i++) cin >> v[i];

    cout << memolized_cut_rod(v, N) << endl;

    return 0;
}
