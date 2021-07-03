#include <iostream>
#include <cstring>
using namespace std;
char arr1[1002] , arr2[1002];
int dp[1002][1002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> arr1;
    cin >> arr2;

    for(int i = 0; i < strlen(arr1); i++){
        for(int j = 0; j < strlen(arr2); j++){
            if (arr1[i] == arr2[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = max(dp[i+1][j] , dp[i][j+1]);
        }
    }
    cout << dp[strlen(arr1)][strlen(arr2)];
    return 0;
}