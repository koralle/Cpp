#include <iostream>
using namespace std;


int main(void){
    long long N;
    cin >> N;

    long long tmp = N;
    for (long long i = 1; i * i <= N; i++){
        if (N % i == 0) {
            if(i + (N / i) - 2 <= tmp)
                tmp = i + (N / i) - 2;
        }
    }

    cout << tmp << endl;

    return 0;
}