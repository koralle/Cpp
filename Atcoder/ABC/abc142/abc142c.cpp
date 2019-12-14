#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long N;
    cin >> N;
    vector<pair <long long, long long>> records(N);
    for (long long i = 0; i < N; i++) {
        long long record;
        cin >> record;
        records[i] = make_pair(record, i);
    }

    sort(records.begin(), records.end());

    for(int j = 0; j < N; j++) {
        cout << records[j].second + 1;
        if (j == N-1) cout << endl;
        else cout << " ";
    }

    return 0;
}