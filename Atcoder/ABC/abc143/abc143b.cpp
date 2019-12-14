#include <iostream>
#include <vector>

int main(void){
    int N;
    std::cin >> N;
    std::vector<int> D(N);
    for (int i = 0; i < N; i++){
        std::cin >> D[i];
    }

    int sum_recovery = 0;
    for(int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            sum_recovery += D[i] * D[j];
        }
    }

    std::cout << sum_recovery << std::endl;

    return 0;
}