#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
     int N, D;
     cin >> N >> D;

     // N x N 行列の定義and初期化
     vector<vector<vector<int> > arr_x(N, vector<int>(N, 0));
     for(in i = 0; i < N; i++){
         for(int j = 0; j < D; j++) cin >> arr_x[i][j];
     }

     for(int i = 0; i < N; i++){
         for(int j = i+1; j < N; j++){
             int distance = 0;
             for(int k = 0; k < D; k++){
                 distance += abs((arr_x[i][k]) * (arr_x[i][k]) - (arr_x[j][k]) * (arr_x[j][k]));
             }


         }
     }


    return 0;
}
