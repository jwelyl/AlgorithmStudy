#include <iostream>
using namespace std;
int position[11][11];
int arr[11]; // 적합한 포지션을 담는 배열
bool isused[11];
int result = 0; // 최댓값 

void recursive(int level , int sum){
    if (level == 11){
        result = max(result , sum);
        return;
    }

    for(int i = 0; i < 11; i++){
        if(position[level][i] == 0) continue;
        
        if (!isused[i]){
            isused[i] = 1;
            recursive(level + 1 , sum + position[level][i]);
            isused[i] = 0;
        }
    }
   
}
int main(){
    int c;
    cin >> c;
    while(c--){
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 11; j++){
                cin >> position[i][j];
            }
        }
    }
    recursive(0,0);
    cout << result;
}